# Validation record

Checked 23 October 2026.

- Python demo and unittest: PASS. See `reconstruction/test-output.txt` and `reconstruction/demo-output.json`. Demo values are synthetic, not project measurements.
- Arduino UNO compilation: PASS (`arduino:avr:uno`, AVR core 1.8.8). See `reconstruction/compile-uno.log`.
- Classic ESP32 compilation: PASS (`esp32:esp32:esp32`, ESP32 core 3.3.12). See `reconstruction/compile-esp32.log`.

Compilation checks syntax, board APIs and linking. It does not verify wiring, voltages, sensor conditioning, actuator behavior or timings on hardware. Python checks exercise a separate logic model; they do not execute the compiled sketch. No physical hardware, clinical test, road trial or historical experiment was performed.

Exact library versions are recorded in the local `toolchain-versions.txt`.

## New bench evidence to collect

Record controller and module part numbers, firmware commit, power rails, calibration method and timestamp. Capture a normal case, an invalid/disconnected input, restart behavior, and timing boundaries where relevant. Save raw data and a real build photograph alongside the new test report. For analytical projects, retain input data, units and independent reference calculations.
