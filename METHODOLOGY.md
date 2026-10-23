# Fingerprint solenoid smart lock: methodology

Status: researched reconstruction / proposed evaluation, prepared 23 October 2026. Not a recovered lab notebook.

## Existing account

An Arduino-controlled solenoid lock that checks fingerprints before actuating the lock through a relay.

The account above comes from the existing portfolio and is not independent verification. Listed stack: Arduino, Solenoid Lock, Fingerprint Sensor, Relay. Exact components and versions still need confirmation.

## System architecture

Fingerprint match -> authorization -> timed lock actuator -> relock/fault

## Proposed engineering workflow

1. Separate enrollment authority from everyday unlock permissions.
2. Require an explicit successful match and bound actuator energization.
3. Document power-loss behavior and manual release before choosing lock mode.
4. Bench-test with a dummy mechanism and monitor driver protection.

## Evaluation plan, not results

Record: Unlock/relock timing; denied matches; power-loss behavior. Use explicit units, test conditions, a baseline where relevant, repeated observations and a timestamped log. Report failure cases alongside successes. No numerical result is available from this reconstruction.

## Limitations and claim boundaries

Do not claim tamper resistance or building-code compliance. Match confidence is not a probability of identity.

## Design questions for an interview

- Explain the input, decision and output paths in the architecture above.
- What concrete fault would invalidate the output, and how would you detect it?
- Which design decision did you personally make, and what evidence do you retain?
- Which part of this proposed workflow differs from what you actually built?

## Research basis

[Adafruit optical fingerprint sensor](https://learn.adafruit.com/adafruit-optical-fingerprint-sensor/overview) — consulted 23 October 2026. This source supports the underlying engineering topic, not the historical implementation. Workflow and evaluation proposals above are original analysis for this project.
