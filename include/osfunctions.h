#include "display/lvgl.h"
#include "main.h"
#pragma once
//-----------------------------------------------//
lv_obj_t * lockScreen = lv_obj_create(NULL, NULL);
lv_obj_t * compScreen = lv_obj_create(NULL, NULL);
lv_obj_t * Home = lv_obj_create(NULL, NULL);
lv_obj_t * settingsScreen = lv_obj_create(NULL, NULL);
lv_obj_t * filesScreen = lv_obj_create(NULL, NULL);
//-----------------------------------------------//


static lv_res_t osAction(lv_obj_t * btn);
static lv_res_t compAction(lv_obj_t * btn);
static lv_res_t settingsAction(lv_obj_t * btn);
static lv_res_t filesAction(lv_obj_t * btn);
static lv_res_t exitAction(lv_obj_t * btn);
static lv_res_t changeTheme(lv_obj_t * btn);
