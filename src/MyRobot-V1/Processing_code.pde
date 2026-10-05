import processing.serial.*;

Serial port;
PrintWriter output;

String lastCmd = "none";
String encoderData = "";

void setup() {
  size(600, 250);

  printArray(Serial.list());

  // Change [2] to whichever port is your Arduino
  port = new Serial(this, Serial.list()[2], 9600);
  port.bufferUntil('\n');

  // Create the CSV file
  output = createWriter("encoder_data.csv");

  // CSV headings
  output.println("t_ms,left_encoder,right_encoder");

  textSize(20);
}

void draw() {
  background(30);
  fill(255);

  text("Last command: " + lastCmd, 20, 80);
  text("Encoder: " + encoderData, 20, 130);
}


// Receive Arduino data
void serialEvent(Serial port) {

  String data = port.readStringUntil('\n');

  if (data != null) {
    data = trim(data);

    encoderData = data;

    // Show in Processing console
    println(data);

    // Save to CSV
    // Don't save Arduino's header again
    if (!data.startsWith("t_ms")) {
      output.println(data);
      output.flush();
    }
  }
}


// Keyboard controls
void keyPressed() {

  char k = key;

  if (k == 'w' || k == 's' ||
      k == 'a' || k == 'd' ||
      k == 'q' || k == 'e' ||
      k == ' ' || k == '+' ||
      k == '-' || k == 't') {

    port.write(k);

    lastCmd = (k == ' ') ? "STOP" : str(k);
  }
}


void keyReleased() {

  if (key == 'w' || key == 's' ||
      key == 'a' || key == 'd' ||
      key == 'q' || key == 'e') {

    port.write(' ');
    lastCmd = "STOP";
  }
}


// Close the CSV properly when you stop
void exit() {
  output.flush();
  output.close();

  super.exit();
}
