// Tonokip RepRap firmware rewrite based off of Hydra-mmm firmware.
// Licence: GPL
#include <WProgram.h>

void get_command();
void process_commands();

void manage_inactivity(byte debug);

void manage_heater();
int temp2analogu(int celsius, const short table[][2], int numtemps, int source);
int analog2tempu(int raw, const short table[][2], int numtemps, int source);
#ifdef HEATER_USES_THERMISTOR
    #define HEATERSOURCE 1
#endif
#ifdef HEATER_USES_AD595
    #define HEATERSOURCE 2
#endif
#ifdef HEATER_USES_MAX6675
    #define HEATERSOURCE 3
#endif
#ifdef BED_USES_THERMISTOR
    #define BEDSOURCE 1
#endif
#ifdef BED_USES_AD595
    #define BEDSOURCE 2
#endif
#ifdef BED_USES_MAX6675
    #define BEDSOURCE 3
#endif

#define temp2analogh( c ) temp2analogu((c),temptable,NUMTEMPS,HEATERSOURCE)
#define temp2analogBed( c ) temp2analogu((c),bedtemptable,BNUMTEMPS,BEDSOURCE)
#define analog2temp( c ) analog2tempu((c),temptable,NUMTEMPS,HEATERSOURCE)
#define analog2tempBed( c ) analog2tempu((c),bedtemptable,BNUMTEMPS,BEDSOURCE)
#if X_ENABLE_PIN > -1
#define  enable_x() digitalWrite(X_ENABLE_PIN, X_ENABLE_ON)
#define disable_x() digitalWrite(X_ENABLE_PIN,!X_ENABLE_ON)
#else
#define enable_x() ;
#define disable_x() ;
#endif
#if Y_ENABLE_PIN > -1
#define  enable_y() digitalWrite(Y_ENABLE_PIN, Y_ENABLE_ON)
#define disable_y() digitalWrite(Y_ENABLE_PIN,!Y_ENABLE_ON)
#else
#define enable_y() ;
#define disable_y() ;
#endif
#if Z_ENABLE_PIN > -1
#define  enable_z() digitalWrite(Z_ENABLE_PIN, Z_ENABLE_ON)
#define disable_z() digitalWrite(Z_ENABLE_PIN,!Z_ENABLE_ON)
#else
#define enable_z() ;
#define disable_z() ;
#endif
#if E_ENABLE_PIN > -1
#define  enable_e() digitalWrite(E_ENABLE_PIN, E_ENABLE_ON)
#define disable_e() digitalWrite(E_ENABLE_PIN,!E_ENABLE_ON)
#else
#define enable_e() ;
#define disable_e() ;
#endif

void FlushSerialRequestResend();
void ClearToSend();

void get_coordinates();
void prepare_move();
void linear_move(unsigned long x_steps_remaining, unsigned long y_steps_remaining, unsigned long z_steps_remaining, unsigned long e_steps_remaining);
void do_step(int axis);
void kill(byte debug);

