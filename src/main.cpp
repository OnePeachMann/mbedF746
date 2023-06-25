#include <mbed.h>
#include <threadLvgl.h>

#include "demos/lv_demos.h"
#include <cstdio>

AnalogIn sensorPin(A0);  // Replace A0 with the appropriate pin for your board
lv_obj_t *screen;
lv_obj_t *label;
ThreadLvgl threadLvgl(30);
void updateSensorValue()
{
    // Lecture de la valeur du capteur
    float sensorValue = sensorPin.read();

    // Convertion de la valeur en string
    char buffer[10];
    sprintf(buffer, "%.2f", sensorValue);

    // mise a jour du label avec la valeur du capteur
    lv_label_set_text(label, buffer);
}
int main() {
    
    lv_init();
    //threadLvgl.lock();
    Thread lvgl_thread(osPriorityNormal, 8 * 1024);
    //lv_init_thread();
    //lv_demo_widgets();
screen = lv_obj_create(lv_scr_act());
    lv_scr_load(screen);
    label = lv_label_create(lv_scr_act());
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(label, "Initializing...");
        //lvgl_thread.start(callback(lvgl_thread_function));
         //RtosTimer sensorTimer(updateSensorValue, osTimerPeriodic, NULL);
    //sensorTimer.start(1000);  // Update every 1 second

    //threadLvgl.unlock();

    while (1) {
        ThisThread::sleep_for(10ms);
    }
}