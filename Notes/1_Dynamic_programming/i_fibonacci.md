# Execution tree: `fibo_recursive(4)`

```text
f(4)
├── f(3)
│   ├── f(2)
│   │   ├── f(1) -> 1
│   │   └── f(0) -> 0
│   └── f(1) -> 1
└── f(2)
    ├── f(1) -> 1
    └── f(0) -> 0
```

Repeated work: `f(2)`, `f(1)`

# Execution tree: `fibo_memo(4)`

```text
f(4)
├── f(3)
│   ├── f(2)
│   │   ├── f(1) -> 1
│   │   └── f(0) -> 0
│   └── f(1) -> cache hit
└── f(2) -> cache hit
```

Each value: computed once, reused later.