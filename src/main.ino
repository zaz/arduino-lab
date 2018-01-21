#define LED_PIN 13
#define CYCLE 100

int delay_time = 50;
bool mcLED [40] = {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0,
                   1, 0, 1, 0, 1, 0, 0, 0,
                   1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0,
                   0, 0, 0, 0};
bool l0 [8] = {1, 1, 1, 1, 0, 0, 0, 0};
bool l1 [8] = {0, 1, 1, 1, 1, 0, 0, 0};
bool l2 [8] = {0, 0, 1, 1, 1, 1, 0, 0};
bool l3 [8] = {0, 0, 0, 1, 1, 1, 1, 0};
bool p0 [4] = {1, 0};
bool p1 [4] = {1, 0};
bool p2 [4] = {0, 1};
bool p3 [4] = {0, 1};

void setup() {
	Serial.begin(9600);
	pinMode(LED_PIN, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
}

void loop() {
	for (int i=0; i < 120; i++) {
		digitalWrite(LED_PIN, mcLED[i % 40]);
		if (i < 80) {
			digitalWrite(9,  l0[int(i/2) % 8]);
			digitalWrite(10, l1[int(i/2) % 8]);
			digitalWrite(11, l2[int(i/2) % 8]);
			digitalWrite(12, l3[int(i/2) % 8]);
		} else {
			digitalWrite(9,  p0[int(i/4) % 2]);
			digitalWrite(10, p1[int(i/4) % 2]);
			digitalWrite(11, p2[int(i/4) % 2]);
			digitalWrite(12, p3[int(i/4) % 2]);
		}
		delay(CYCLE);  // cycles will be slightly longer than CYCLE ms
	}
}
