void setup() {
  // Initialize serial communication at 115200 baud rate
  Serial.begin(115200);

  // Wait for the serial port to connect
  while (!Serial) {
    ; // Do nothing, wait for connection
  }

  // Give the terminal emulator time to attach before sending text
  delay(2000);

  // Print initial greeting to MiniCom once on startup
  Serial.println("Hello World");
}

void loop() {
  // --- BIDIRECTIONAL UART INTERFACE ---
  // Signal to the terminal that the Pico is waiting for a command
  Serial.print("\n[UART Ready] Enter a Pico command: ");
  
  while (Serial.available() == 0) { }
  if (true) {

    // Read the incoming string until a newline character is received
    String incomingData = Serial.readStringUntil('\n');

    // Trim any trailing carriage returns or whitespaces
    incomingData.trim();

    // Move cursor to a new line before responding
    Serial.println(); 

    // Confirm receipt of the bidirectional transmission
    Serial.print(">>> Bidirectional RX Success: ");
    Serial.println(incomingData);

    // CLEAR LEFTOVER CHARACTERS: Cleans the serial buffer
    while (Serial.available() > 0) {
      Serial.read(); 
    }
  }

  // Small delay to keep the loop stable and prevent high CPU usage
  delay(50);
}
