
const int rowPin0 = 0;
const int rowPin1 = 1;
const int rowPin2 = 2;
const int rowPin3 = 3;
const int columnPin0 = 4;
const int columnPin1 = 5;
const int columnPin2 = 6;
const int strikePin = 7;

int pinCodeRingBuffer[4];
int currentPinIndex = 0;




void setup(){
    pinMode(rowPin0, OUTPUT);
    digitalWrite(rowPin0, HIGH);

    pinMode(rowPin1, OUTPUT);
    digitalWrite(rowPin1, HIGH);

    pinMode(rowPin2, OUTPUT);
    digitalWrite(rowPin2, HIGH);

    pinMode(rowPin3, OUTPUT);
    digitalWrite(rowPin3, HIGH);

    pinMode(columnPin0, INPUT_PULLUP);
    pinMode(columnPin1, INPUT_PULLUP);
    pinMode(columnPin2, INPUT_PULLUP);

    digitalWrite(strikePin, LOW);

    resetPinCode();
}




const int columns[] = { columnPin0, columnPin1, columnPin2 };
const int rows[] = { rowPin0, rowPin1, rowPin2, rowPin3 };
const int matrix[4][3] = 
    { 1, 2, 3
    , 4, 5, 6
    , 7, 8, 9
    ,10, 0, 11
    };
const int rowIdentityMatrix[4][4] =
    { LOW, HIGH, HIGH, HIGH
    , HIGH, LOW, HIGH, HIGH
    , HIGH, HIGH, LOW, HIGH
    , HIGH, HIGH, HIGH, LOW
    };

void loop(){
    gateKeep(getCurrentKey());
}

int canRegisterKeyPress[4][3] =
    { 1, 1, 1
    , 1, 1, 1
    , 1, 1, 1
    , 1, 1, 1
    };
int getCurrentKey() {
    int currentPressedKey = -1;
    for (int r = 0; r < 4; r++)
    {
        for (int i = 0; i < 4; i++)
        {
            digitalWrite(rows[i], rowIdentityMatrix[r][i]);
        }
        for (int c = 0; c < 3; c++)
        {
            const bool pressingKey = digitalRead(columns[c]) == LOW;
            if (pressingKey && canRegisterKeyPress[r][c])
            {
                canRegisterKeyPress[r][c] = false;
                currentPressedKey = matrix[r][c];
            }
            else if (!pressingKey)
            {
                canRegisterKeyPress[r][c] = true;
            }
            delay(2);
        }
        delay(3);
    }
    return currentPressedKey;
}




bool canSendKey = true;
void gateKeep(int key) {
    if (canSendKey && key >= 0)
    {
        canSendKey = false;
        updateRingBuffer(key);
        maybeStrikeIt();
    }
    else if (key < 0)
    {
        canSendKey = true;
    }
}



void updateRingBuffer(int key) {
    pinCodeRingBuffer[currentPinIndex] = key;
    currentPinIndex = (currentPinIndex + 1) % 4;
}




void maybeStrikeIt() {
    int code[] = { 1, 8, 4, 8 };
    
    // Check if the strike should strike out
    for (int i = 0; i < 4; i ++)
    {
        bool isValidMatch = true;
        for (int j = 0; j < 4; j++)
        {
            if (pinCodeRingBuffer[(i+j) % 4] != code[j])
            {
                isValidMatch = false;
                break;
            }   
        }
        if (isValidMatch)
        {
            reallyStrikeIt();
            resetPinCode();
            break;
        }
    }
}




void reallyStrikeIt() {
    digitalWrite(strikePin, HIGH);
    delay(3000);
    digitalWrite(strikePin, LOW);
}




void resetPinCode() {
    pinCodeRingBuffer[0] = pinCodeRingBuffer[1] = pinCodeRingBuffer[2] = pinCodeRingBuffer[3] = 99;
}
