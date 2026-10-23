# Source entry points

Runnable new implementation: `reconstruction/model.py`; checks: `reconstruction/test_model.py`. Hardware implementation: `reconstruction/firmware/firmware.ino`. Read `CIRCUIT.md` before use.

## Earlier design notes

# Code and implementation record

## Original source status

Historical portfolio description only; original source, measurements and photographs not supplied.

No original code recovered for this project. Exact pin maps, libraries, timings and circuit values are intentionally not invented.

## Reconstructed pseudocode

This is newly written explanatory pseudocode, not executable firmware and not historical evidence.

```text
if authorized match and no fault: energize for bounded duration
then relock
on timeout or invalid state: enter documented fault mode
```

## What is needed before implementation

Confirm actual hardware/software interfaces, units, validation rules and failure states. Follow the separate methodology and its test plan. Do not claim tamper resistance or building-code compliance. Match confidence is not a probability of identity.
