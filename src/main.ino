#define LED_PIN 13
#define CYCLE 100

int delay_time = 50;

void dot() {
	digitalWrite(LED_PIN, 1);
	delay(CYCLE);
	digitalWrite(LED_PIN, 0);
	delay(CYCLE);
}

void dash() {
	digitalWrite(LED_PIN, 1);
	delay(3 * CYCLE);
	digitalWrite(LED_PIN, 0);
	delay(CYCLE);
}

void end_letter() {
	digitalWrite(LED_PIN, 0);
	delay(2 * CYCLE);
}

void space() {
	digitalWrite(LED_PIN, 0);
	delay(4 * CYCLE);
}

void setup() {
	Serial.begin(9600);
	pinMode(LED_PIN, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	digitalWrite(9, 1);
	digitalWrite(10, 1);
	digitalWrite(11, 1);
	digitalWrite(12, 1);
}

void loop() {
	dot(); dash(); dash(); dash(); end_letter();
	dot(); dot(); dot(); end_letter();
	dash(); dot(); dot(); dot(); end_letter();
	space();
}
