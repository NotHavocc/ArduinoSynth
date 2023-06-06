  ArduinoSynth by NotHavoc (2023)
  ***

  Mini tone generator for your mini board.
  Change tone pitch using the potenciometer.
  Three buttons which have slightly higher pitch, press them to create a tone.
  RGB LED to indicate the status of pressed button
  OLED to display current settings (optional)
  4th button to change delay inbetween the tones
  I used a speaker extracted off a toy piano, but you can use a piezo or any other speaker module.
  ***

  Connect to the following pins :
    button1 = 10,
    button2 = 5,
    button3 = 11,
    button4 = 8,
    ledR = 7,
    ledG = 3,
    ledB = 2,
    Speaker = 9,
    Potenciometer = A0,
    OLED SDA = A5,
    OLED SCL = A4 (Find I2C pins for your board if your not using an arduino nano/uno.)
    
    Schematic will be saved in the file WIRING.PNG 📸
   ***
