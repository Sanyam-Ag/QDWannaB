# Motivation & Aim

>This project implements a minimal statistical analytics engine focused on numerical correctness, modularity, and build discipline.

>C++ is used as the core language to provide deterministic performance, explicit memory control, and a strong foundation for future extensions.  
Python is planned as an integration layer in later versions to improve usability and ecosystem access, but is explicitly excluded from v0.1.

>The current version intentionally limits functionality to a small set of statistical operations to ensure correctness before feature expansion.

## Version 0.1 Scope

1. CLI Based execution model
2. Stateless execution
3. CMake Build system
4. Custom Minimal Test files
5. Statistical operations available:
    a. Mean
    b. Variance
6. Single data field support
7. Custom parser restricted to integer/double type values
8. Excluded:
    a. File I/O
    b. Networking
    c. Visulaization
    d. Performance Optimization
    e. Python and external library support

### Architecture Explained

>Dependency is one directional

```
    core/ contains domain logic and has no dependency on CLI or tests.
    cli/ depends on core but not vice versa.
    tests/ depends on core and stats modules only
```

>This structure ensures that domain logic remains independent of presentation and tooling, enabling future reuse in other interfaces (eg. Python bindings).
>This prevents UI, tooling, or test concerns from leaking into core logic.

### Build & Tooling Decisions

>CMake was chosen to provide a platform-independent build system and explicit target-level dependency management.

In v0.1:
- A single test executable is used to minimize build complexity
- Tests are compiled separately from the CLI binary
- No external dependencies are introduced

This prioritizes build correctness and clarity over flexibility.

### Testing Philosophy

>Testing in v0.1 focuses on correctness of core statistical logic rather than exhaustive coverage.

- Tests are implemented as a single executable with a custom runner
- Assertions are used to fail fast on incorrect behavior
- No test framework is used to ensure understanding of compilation, linking, and execution flow

This approach is intentionally minimal and will be revisited in later versions.


### Expectations for v0.2
1. Extended statistical methods
2. Multiple data field support
3. Improved command parsers and validators