# Design Document — v0.2

Interactive CLI, Command System, and Dataset Model

---

## Overview

Version v0.2 extends the v0.1 core time-series engine by introducing an interactive command-line interface (CLI) with a Read–Eval–Print Loop (REPL), a structured command execution system, and minimal multi-column dataset support.

The primary goal of v0.2 is **architectural clarity and extensibility**, not feature richness or performance. This version establishes the foundations required for future work such as advanced analytics, visualization, and external bindings.

---

## Goals

* Provide a stable, extensible REPL-based CLI
* Introduce a command abstraction decoupled from core logic
* Support basic statistical operations on named columns
* Maintain strict dependency direction and modularity
* Preserve correctness and testability

---

## High-Level Architecture

The v0.2 system is structured into four layers with **one-way dependencies**:

```
    CLI (REPL)
    ↓
    Parser
    ↓
    Command System
    ↓
    Core Engine (v0.1)
```

* The **core engine** remains UI-agnostic and unaware of the CLI.
* The **command system** acts as the sole interface between user input and core logic.
* The **parser** performs minimal tokenization and validation.
* The **REPL** coordinates input, execution, and error handling.

This separation ensures that future interfaces (e.g. GUI, bindings) can reuse the command layer without modification.

---

## REPL Design

The REPL is responsible only for orchestration:

1. Read user input
2. Invoke the parser
3. Dispatch commands via the registry
4. Handle and report errors
5. Continue until explicit exit

The REPL contains **no business logic** and **no command-specific behavior**.

All exceptions are caught at the REPL boundary to prevent uncontrolled termination.

---

## Command System

### Command Abstraction

Each CLI command is represented by a concrete implementation of a common interface.

Responsibilities:

* Declare a command name
* Provide help text
* Execute logic using parsed arguments

Commands are **stateless** and operate only on inputs provided at execution time.

This design avoids conditional logic (e.g. `if/else`, `switch`) in the REPL and enables straightforward extension.

---

### Command Registry

The command registry maintains ownership of all available commands.

Responsibilities:

* Register commands at startup
* Resolve commands by name
* Dispatch execution

The registry provides a single point of control for command availability and avoids tight coupling between commands.

---

## Parser Design

The parser performs **minimal, deterministic processing**.

Responsibilities:

* Split input on whitespace
* Extract command name and arguments
* Handle empty or invalid input

The parser does **not**:

* Perform semantic validation
* Interpret data types
* Manage command execution

This deliberate simplicity ensures predictability and testability.

---

## Dataset and Multi-Column Support

v0.2 introduces a minimal dataset abstraction to support multi-column operations.

### Dataset Model

A dataset is defined as a collection of **named numeric columns**, each represented by a `TimeSeries`.

Characteristics:

* Columns are accessed by name
* No implicit alignment or indexing logic
* No missing value handling
* No schema inference

This model supports expressions such as:

```
mean prices.close
std prices.volume
```

without introducing DataFrame-level complexity.

---

## Statistical Operations

v0.2 extends the set of supported statistical functions to include:

* mean
* variance
* standard deviation
* min / max
* count

All operations are:

* Column-wise
* Stateless
* Deterministic

Operations requiring temporal context or multiple series (e.g. rolling statistics, correlations) are intentionally deferred in the current version.

---

## Error Handling Strategy

* User input errors are reported with clear, human-readable messages
* Unknown commands result in explicit feedback
* Core logic errors propagate via exceptions and are handled at the REPL boundary
* Assertions are reserved for tests and internal invariants

---

## Testing Philosophy (v0.2)

Tests are extended to cover:

* Parser tokenization and edge cases
* Command lookup and dispatch
* Dataset column access
* Error conditions for invalid input

As in v0.1, tests prioritize correctness and clarity over completeness.

No external testing framework is introduced at this stage.

---

## Backward Compatibility

All public interfaces introduced in v0.1 remain unchanged.

The core time-series and statistical components are reused without modification, validating the dependency direction established in earlier versions.

---

## Roadmap Beyond v0.2

v0.2 establishes the foundation for:

* Visualization or terminal UI (e.g. ncurses, Vim-like modes)
* File I/O (CSV, Parquet, etc.)
* Networking or remote data access
* Python / JavaScript bindings
* Performance optimizations
* Advanced statistical operations (rolling windows, correlations)

These features will be addressed incrementally once the command and dataset abstractions prove stable.

---

## Summary

Version v0.2 prioritizes **structure over scale**.
By focusing on a clean REPL, command system, and minimal dataset model, the project transitions from a static library into an interactive analytical tool while preserving long-term extensibility.

---
