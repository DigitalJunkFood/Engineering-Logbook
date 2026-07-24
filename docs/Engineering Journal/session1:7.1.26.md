# Session 001

**Date:** July 1, 2026

## Objective

Continue integrating the greenhouse control system by combining the servo motor, DC motor, and environmental sensor into a single control program.

## Software Experiments

Tested two additional control programs intended to coordinate all three hardware components.

During testing, the DC motor appeared to be non-functional. Investigation showed the issue was not hardware failure, but excessive `delay()` timing that prevented observable responses.

Additional debugging revealed that misplaced curly braces isolated sections of the program, preventing portions of the logic from executing.

### Resolution

- Reduced unnecessary delay times.
- Divided the software into smaller functional blocks.
- Corrected misplaced curly braces.
- Verified operation of individual components before reintegration.

## Mechanical Testing

Performed repeated servo tests to determine the optimal angles required to fully open and close the greenhouse lid.

These measurements will later become fixed calibration values in the automation software.

## Engineering Notes

The final greenhouse program will:

- Monitor temperature and humidity.
- Compare readings against predefined thresholds.
- Open the greenhouse lid when ventilation is required.
- Run the cooling fan until environmental conditions return to acceptable levels.

## Next Steps

- Research optimal growing conditions.
- Determine activation thresholds.
- Continue integrating all hardware into a single program.

## Lessons Learned

- Debug one subsystem at a time.
- Long software delays can imitate hardware failures.
- Smaller code blocks simplify troubleshooting.
