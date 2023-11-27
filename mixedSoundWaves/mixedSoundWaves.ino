// // Teensy 4.1 Tone Example

// #define SPEAKER_PIN 10 // Connect your speaker or buzzer to this pin

// void setup() {
//   pinMode(SPEAKER_PIN, OUTPUT);
// }

// void loop() {
//   tone(SPEAKER_PIN, 10000); // Generate a 440 Hz tone (A4 note)
//   delay(1000);           // Play the tone for 1000 milliseconds (1 second)
//   noTone(SPEAKER_PIN);   // Stop the tone
//   delay(1000);           // Wait for 1000 milliseconds (1 second)
// }

const int frequency1 = 500;  // Frequency of the first square wave
const int frequency2 = 1000; // Frequency of the second square wave

int speakerPin = 10;  // Speaker connected to pin 10

void setup() {
  pinMode(speakerPin, OUTPUT);
  analogWriteResolution(8); // Set PWM resolution
}

void loop() {
  for (int i = 0; i < 255; ++i) {
    int wave1 = (i * frequency1 / 1000) % 255 < 127 ? 127 : 0; // Generate first square wave
    int wave2 = (i * frequency2 / 1000) % 255 < 127 ? 127 : 0; // Generate second square wave
    int mixedWave = (wave1 + wave2) / 2; // Mix the two waves
    analogWrite(speakerPin, mixedWave); // Output mixed wave
    delayMicroseconds(1000); // Small delay to control the frequency of the loop

  }
}

