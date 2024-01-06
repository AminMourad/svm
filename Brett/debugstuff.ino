//RAM query
extern unsigned long _heap_start;
extern unsigned long _heap_end;
extern char *__brkval;




int freeram() {
  return (char *)&_heap_end - __brkval;
}

void prfr(){
  Serial.print("freeram = ");
  Serial.println(freeram());
  }
