# Real-Time System Telemetry Pipeline

A real-time system telemetry pipeline in C++17 simulating an embedded environment. The project relies on a modular architecture featuring a metric producer process, a consumer displaying a dynamic terminal user interface (TUI), and inter-process communication (IPC) via an anonymous Unix pipe.

## Features
- **Producer (`producer`):** Continuous generation of system metrics (CPU, RAM, temperature, status flags) serialized into CSV format.
- **Consumer (`consumer`):** Interactive dashboard rendering directly in the terminal.
- **TUI & Metrics Tracking:** Dynamic progress bars, peak value indicators, ASCII history graph (*sparkline*), and ANSI color-coded status alerts.

---

## Build Instructions

At the root of the project repository:

```bash
mkdir build && cd build
cmake ..
make
```

## Usage

Run the pipeline by connecting the producer stream to the consumer via a Unix pipe:

```bash
./producer/producer | ./consumer/consumer
```

### Preview

<img width="300" height="198" alt="Capture d’écran 2026-10-29 à 05 08 38" src="https://github.com/user-attachments/assets/77b54151-2fc7-44fb-b1b0-d18a63107e09" />
