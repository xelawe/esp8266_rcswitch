// 1 - 10111001011110011110011100000000 (3111773952),
// 0 - 10110101011110011110011100000000 (3044665088)
#include <RCSwitch.h>
#include "output.h"

RCSwitch mySwitch = RCSwitch();


void init_switch() {

  mySwitch.enableReceive(5);  // Receiver on interrupt 0 => that is pin #2

  // Transmitter is connected to Arduino Pin #D4
  mySwitch.enableTransmit(4);

  // Optional set pulse length.
  mySwitch.setPulseLength(692);

  // Optional set protocol (default is 1, will work for most outlets)
  mySwitch.setProtocol(2);


}


void check_switch() {
  if (mySwitch.available()) {
    output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(), mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
  }
}

void send_switch(int iv_state) {
  if ( iv_state == 1 ) {
    mySwitch.send("10111001011110011110011100000000");
  }
  else {
    mySwitch.send("10110101011110011110011100000000");
  }

}







