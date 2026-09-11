# Memoization idea

Visualize as a tree, getting a working solution using recursion, add a memo object.

# Execution tree: `fibo_recursive(6)`

```mermaid
flowchart TB
    r6((fib 6)) --> a5((fib 5)) & b4((fib 4))

    a5 --> a4((fib 4)) & a3((fib 3))
    a4 --> a3l((fib 3)) & a2((fib 2))
    a3l --> a2l((fib 2)) & a1l((fib 1))
    a2l --> a1a((fib 1)) & a0a((fib 0))
    a2 --> a1c((fib 1)) & a0c((fib 0))
    a3 --> a2r((fib 2)) & a1r((fib 1))
    a2r --> a1b((fib 1)) & a0b((fib 0))

    b4 --> b3((fib 3)) & b2((fib 2))
    b3 --> b2l((fib 2)) & b1((fib 1))
    b2l --> b1l((fib 1)) & b0l((fib 0))
    b2 --> b1r((fib 1)) & b0r((fib 0))

    classDef nodeStyle fill:#102a43,stroke:#d9e2ec,color:#fff,stroke-width:2px
    class r6,a5,b4,a4,a3,a3l,a2,a2l,a1l,a2r,a1r,b3,b2,b2l,b1,a1a,a0a,a1b,a0b,a1c,a0c,b1l,b0l,b1r,b0r nodeStyle
```

Repeated work: `fib 4`, `fib 3`, `fib 2`, `fib 1`, `fib 0`

# Execution tree: `fibo_memo(6)`

```mermaid
flowchart TB
    m6((fib 6)) --> m5((fib 5))
    m5 --> m4((fib 4))
    m4 --> m3((fib 3))
    m3 --> m2((fib 2))
    m2 --> m1((fib 1)) & m0((fib 0))

    m3 --> hit1["fib 1: base return"]
    m4 --> hit2["fib 2: cache hit"]
    m5 --> hit3["fib 3: cache hit"]
    m6 --> hit4["fib 4: cache hit"]

    classDef nodeStyle fill:#102a43,stroke:#d9e2ec,color:#fff,stroke-width:2px
    classDef base fill:#1f7a8c,stroke:#d9e2ec,color:#fff,stroke-width:2px
    classDef cache fill:#7c4d9e,stroke:#d9e2ec,color:#fff,stroke-width:2px
    class m6,m5,m4,m3,m2 nodeStyle
    class m1,m0,hit1 base
    class hit2,hit3,hit4 cache
```

Computed once. Reused from cache.