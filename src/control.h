
#ifndef CONTROL_H
#define CONTROL_H

#define INPUT_MIN     16    // Minimum empirical output from ADC
#define INPUT_MAX     1020  // Maximum empirical output from ADC
#define ADC_PIVOT     512
#define OUTPUT_MIN    0.0
#define OUTPUT_MAX    1.0

#define OUTPUT_RANGE  (OUTPUT_MAX - OUTPUT_MIN)

#define MOTOR_ACTIVE_LOW(adcOut) ( \
  OUTPUT_MIN + OUTPUT_RANGE * ( \
    (double)(INPUT_MAX - (adcOut)) \
    / (double)(INPUT_MAX - ADC_PIVOT) \
  ) \
)

#define MOTOR_ACTIVE_HIGH(adcOut) ( \
  OUTPUT_MIN + OUTPUT_RANGE * ( \
    (double)((adcOut) - INPUT_MIN) \
    / (double)(ADC_PIVOT - INPUT_MIN) \
  ) \
)

#endif
