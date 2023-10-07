class Button {
  private: 
    bool state;
    int pin;

  public: 
    Button(int input) : pin(input){}

    void begin(){
      pinMode(pin, INPUT_PULLUP);
      state = digitalRead(pin);  
    }

    bool isReleased(){
      bool r = digitalRead(pin);
      if (r != state){
        state = r;
        if (state){
          return true;
        }   
      }
      return false;  
    }
};
