#include <DebounceInput.h>
#include <FlexCAN_T4.h>

#define EPStoLKAS Serial2 
#define LKAStoEPS Serial3

#define DIP1 6
#define DIP2 32
#define DIP3 33
#define DIP4 9
#define DIP5 10
#define DIP6 11
#define DIP7 12

#define PB1_RAW 2
#define PB2_RAW 3
#define PB3_RAW 4
#define PB4_RAW 5
#define AIN 26

#define EPS_RX 27
#define EPS_TX 25
#define LKAS_TX 24
#define LKAS_RX 16
#define BLUE_LED 28 //Used for signifying "manipulated" data

#define BLUE_LED_ON digitalWrite(BLUE_LED,HIGH)
#define BLUE_LED_OFF digitalWrite(BLUE_LED, LOW)

DebouncedInput PB1(PB1_RAW);
DebouncedInput PB2(PB2_RAW);
DebouncedInput PB3(PB3_RAW);
DebouncedInput PB4(PB4_RAW);

int messageCounter = 0; // Used to track which byte position we are on when spoofing
int numberOfMessages = 24; //25 messages total need to be sent to "spoof"
int currentByte = 0; // The actual byte that is read
int i = 0;
elapsedMillis timer; // Starts a milisecond counter
elapsedMillis LEDtime;

bool ManipulateLED = 0;
uint16_t LEDtimeON = 100;
uint16_t timeBetweenSpoofs = 5000; // Minimum time required to send a spoofed message

int SpoofBytes[] = {1, 163, 128, 157, 191, 33, 169, 128, 153, 157, 1, 169, 128,
                    164, 178, 33, 169, 128, 148, 162, 1, 165, 128, 147, 199
                   };

void pinSetup();
void EPS_Serial();
void SpoofSteeringData();
void LKAS_Serial();
void ledReset();
void readPB();
void LEDtimer();
void writeLKAStoEPS(int);
int readLKAStoEPS();
void writeEPStoLKAS(int);
int readEPStoLKAStoEPS();

FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;
FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_16> can3;
CAN_message_t msg;


void pinSetup() {
  pinMode(DIP1, INPUT_PULLUP);
  pinMode(DIP2, INPUT_PULLUP);
  pinMode(DIP3, INPUT_PULLUP);
  pinMode(DIP4, INPUT_PULLUP);
  pinMode(DIP5, INPUT_PULLUP);
  pinMode(DIP6, INPUT_PULLUP);
  pinMode(DIP7, INPUT_PULLUP);

  pinMode(EPS_TX, OUTPUT);
  pinMode(EPS_RX, OUTPUT);
  pinMode(LKAS_TX, OUTPUT);
  pinMode(LKAS_RX, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(AIN, INPUT_PULLUP);
}
