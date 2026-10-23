# Fingerprint solenoid smart lock

Secure door lock system using fingerprint authentication.

## Provenance

Ashutosh reports having built the original project. Original portfolio details are preserved in `original-project.json`. The controller family was ESP32, Arduino UNO and, for some experiments, Raspberry Pi. Exact historic wiring is no longer available.

The `reconstruction/` source was newly written on 23 October 2026 to recreate and explain the project logic. It is not the recovered historical source. Pin maps are explicit new implementation choices, not claims about the lost wiring.

## Run the reconstruction

From this project folder:

```powershell
cd reconstruction
python model.py
python -m unittest -v
```

Python 3.10+; standard library only. Demo inputs are synthetic. Tests check the new logic, not historical results.

## Firmware and wiring

Read `CIRCUIT.md` for the bill of materials, connections, voltage levels and required libraries. Open `reconstruction/firmware/firmware.ino` in Arduino IDE. Select ESP32 Dev Module or Arduino UNO and install the listed dependencies. Compile before connecting hardware. See `VALIDATION.md` for the exact board builds checked here. Calibration and physical verification remain to be performed.

## Project documents

- [Bio](BIO.md)
- [Methodology](METHODOLOGY.md)
- [Source guide](CODE.md)
- [Evidence inventory](EVIDENCE.md)
- [Validation](VALIDATION.md)
- [References and offline resources](resources/README.md)

## Continuing this project

Record the actual components used in your new build, photograph its wiring, save raw measurements, and record the test conditions. Commit new results with their real date. Preserve recovered history separately from the reconstruction. No historical performance numbers have been generated.

[Bench test plan](TEST_PLAN.md) lists the next physical checks.
