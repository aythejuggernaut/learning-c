In C, **multi-dimensional arrays are stored as a single contiguous block of memory** in **row-major order**. This means that all the elements of the first row are stored first, followed by all the elements of the second row, and so on.

### Example

```c
int a[3][4] = {
    { 1,  2,  3,  4},
    { 5,  6,  7,  8},
    { 9, 10, 11, 12}
};
```

The memory layout looks like this:

```
Address →
+----+----+----+----+----+----+----+----+----+----+----+----+
| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |10  |11  |12  |
+----+----+----+----+----+----+----+----+----+----+----+----+
```

Not like this (which would be column-major order):

```
1 5 9 2 6 10 ...
```

---

## Address calculation

For an array declared as:

```c
int a[ROWS][COLS];
```

The address of `a[i][j]` is computed as:

[
\text{address}(a[i][j]) =
\text{base} +
(i \times COLS + j) \times sizeof(int)
]

For example:

```c
int a[3][4];
```

Suppose `sizeof(int) == 4` and the base address is `1000`.

Then:

| Element   | Offset           | Address |
| --------- | ---------------- | ------- |
| `a[0][0]` | `(0×4+0)×4 = 0`  | 1000    |
| `a[0][1]` | `(0×4+1)×4 = 4`  | 1004    |
| `a[0][3]` | `(0×4+3)×4 = 12` | 1012    |
| `a[1][0]` | `(1×4+0)×4 = 16` | 1016    |
| `a[2][2]` | `(2×4+2)×4 = 40` | 1040    |

Notice how moving to the next row skips over an entire row (`COLS` elements).

---

## What is `a` really?

Although you write:

```c
a[i][j]
```

the compiler interprets it as:

```c
*(*(a + i) + j)
```

Here's why:

- `a` has type `int [3][4]`.
- In most expressions, it decays to a pointer to its first row: `int (*)[4]`.
- `a + 1` points to the next row (it advances by `4 * sizeof(int)` bytes).
- `*(a + i)` is the `i`th row.
- `*(a + i) + j` points to the `j`th element in that row.
- Dereferencing again gives the value.

---

## Memory visualization

```
int a[3][4];

          Row 0             Row 1             Row 2
        +----+----+----+----+----+----+----+----+----+----+----+----+
Memory: |a00 |a01 |a02 |a03 |a10 |a11 |a12 |a13 |a20 |a21 |a22 |a23 |
        +----+----+----+----+----+----+----+----+----+----+----+----+
```

The rows are contiguous in memory.

---

## Higher-dimensional arrays

The same rule extends to more dimensions.

For:

```c
int b[2][3][4];
```

Memory is laid out as:

```
b[0][0][0]
b[0][0][1]
b[0][0][2]
b[0][0][3]

b[0][1][0]
...
b[0][2][3]

b[1][0][0]
...
b[1][2][3]
```

The last dimension varies the fastest.

The address formula is:

[
\text{address}(b[i][j][k]) =
\text{base} +
((i \times 3 \times 4) + (j \times 4) + k)
\times sizeof(int)
]

---

### Key takeaway

- Multi-dimensional arrays in C are **not arrays of separately allocated arrays**; they are stored in one **contiguous block of memory**.
- C uses **row-major order**, so the **last index changes fastest** in memory.
- `a[i][j]` is equivalent to `*(*(a + i) + j)`, relying on pointer arithmetic and the contiguous row-major layout.

Great. Multi-dimensional arrays are one of the best places to understand **CPU caches, memory locality, and performance optimization** because the way you traverse an array can easily make a program 10× slower or faster.

Let's build from the memory layout we discussed.

## 1. Why cache matters

Modern CPUs are **much faster than RAM**.

Approximate access times:

| Storage      |       Latency |
| ------------ | ------------: |
| CPU register |      ~1 cycle |
| L1 cache     |   ~1–5 cycles |
| L2 cache     | ~10–20 cycles |
| L3 cache     | ~30–70 cycles |
| RAM          |  ~100+ cycles |

So the CPU tries very hard to avoid going to RAM.

The cache works because programs usually have:

1. **Temporal locality**
   If you use something now, you are likely to use it again soon.

2. **Spatial locality**
   If you use something now, you are likely to use nearby memory soon.

Multi-dimensional arrays interact heavily with spatial locality.

---

# 2. Row-major order and cache friendliness

Consider:

```c
#define N 4096

int matrix[N][N];
```

Memory looks like:

```
matrix[0][0]
matrix[0][1]
matrix[0][2]
...
matrix[0][4095]
matrix[1][0]
matrix[1][1]
...
```

The elements of a row are next to each other.

---

## Cache-friendly traversal

```c
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        matrix[i][j]++;
    }
}
```

Access pattern:

```
0 1 2 3 4 5 6 7 ...
-----------------
sequential memory
```

The CPU loads a **cache line** (usually 64 bytes).

If:

```c
sizeof(int) == 4
```

then one cache line contains:

```
64 / 4 = 16 integers
```

So when you access:

```
matrix[0][0]
```

the CPU actually brings:

```
matrix[0][0]
matrix[0][1]
matrix[0][2]
...
matrix[0][15]
```

into cache.

The next 15 accesses are basically free.

---

# 3. Cache-unfriendly traversal

Now reverse the loops:

```c
for (int j = 0; j < N; j++)
{
    for (int i = 0; i < N; i++)
    {
        matrix[i][j]++;
    }
}
```

Access pattern:

```
matrix[0][0]
matrix[1][0]
matrix[2][0]
matrix[3][0]
...
```

Memory:

```
matrix[0][0]
matrix[0][1]
matrix[0][2]
matrix[0][3]
...
matrix[1][0]
```

You are jumping:

```
4096 integers
4096 integers
4096 integers
```

between accesses.

The cache line you loaded contains:

```
matrix[0][0]
matrix[0][1]
...
matrix[0][15]
```

but your next access is:

```
matrix[1][0]
```

which is far away.

Most of that cache line was wasted.

---

# 4. The performance difference

A simple benchmark:

```c
#define N 4096

int a[N][N];

void row_access()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            a[i][j]++;
}


void column_access()
{
    for(int j=0;j<N;j++)
        for(int i=0;i<N;i++)
            a[i][j]++;
}
```

The first version may be several times faster.

Same algorithm.

Same number of operations.

Different memory access pattern.

---

# 5. Cache lines and false intuition

People often think:

> "RAM access is per integer."

It isn't.

The CPU thinks in **cache lines**.

Example:

```c
int x = matrix[0][0];
```

The CPU does not fetch:

```
4 bytes
```

It fetches something like:

```
64 bytes
```

around that address.

This is why sequential access is powerful.

---

# 6. Loop tiling (blocking)

For huge matrices, even row traversal can overflow cache.

Example:

```c
for(i=0;i<N;i++)
    for(j=0;j<N;j++)
        c[i][j]=a[i][j]+b[i][j];
```

Suppose:

```
N = 10000
```

The matrix is enormous:

```
10000 × 10000 × 4 bytes

= 400 MB
```

The cache cannot hold it.

A common optimization is **blocking**:

```c
#define BLOCK 64

for(int ii=0; ii<N; ii+=BLOCK)
{
    for(int jj=0; jj<N; jj+=BLOCK)
    {
        for(int i=ii; i<ii+BLOCK; i++)
        {
            for(int j=jj; j<jj+BLOCK; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    }
}
```

Now instead of:

```
whole matrix
```

you work on:

```
64 × 64 tile
```

which fits better in cache.

---

# 7. Pointer arithmetic optimization

This:

```c
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    {
        matrix[i][j]++;
    }
}
```

requires calculating:

```
base + i*N + j
```

each iteration.

A compiler usually optimizes this, but you can express it directly:

```c
for(int i=0;i<N;i++)
{
    int *row = matrix[i];

    for(int j=0;j<N;j++)
    {
        row[j]++;
    }
}
```

Now:

```
row
 |
 v
[0][1][2][3][4]
```

The inner loop only increments a pointer.

---

# 8. Alignment and SIMD

Modern CPUs can process multiple numbers at once.

Example:

Normal:

```
add:
a[0]+b[0]
a[1]+b[1]
a[2]+b[2]
a[3]+b[3]
```

SIMD:

```
add:
[a0 a1 a2 a3]
+
[b0 b1 b2 b3]

=
[c0 c1 c2 c3]
```

A 256-bit AVX instruction can process:

```
8 floats
```

at once.

Good memory layout makes SIMD much easier.

---

# 9. Data-oriented design

This is why game engines and high-performance software often avoid:

```c
struct Particle
{
    float x;
    float y;
    float z;
    float velocity;
    int color;
};

Particle particles[100000];
```

If you only update positions:

```c
for(...)
{
    particles[i].x += speed;
}
```

you load:

```
x y z velocity color
```

but only use:

```
x
```

Wasteful.

Instead:

```c
struct Particles
{
    float x[100000];
    float y[100000];
    float z[100000];
};
```

Now:

```
x x x x x x x
```

is contiguous.

This is called **Structure of Arrays (SoA)**.

---

# 10. The hierarchy of optimization thinking

A good order is:

```
Algorithm choice
        ↓
Memory access pattern
        ↓
Cache locality
        ↓
Branch prediction
        ↓
SIMD/vectorization
        ↓
Compiler optimizations
        ↓
Micro-optimizations
```

Many programmers jump to the bottom too early.

---

A very useful next topic is **how matrix multiplication is optimized in real BLAS libraries** because it combines everything: cache blocking, SIMD, memory layout, and CPU architecture.
