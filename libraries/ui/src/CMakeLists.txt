SET(SOURCES ui_comp_clockscreenmain.c
    ui_comp.c
    ui_clockScreen.c
    ui_menuScreen.c
    ui_spotifyScreen.c
    ui_calendarScreen.c
    ui_aboutScreen.c
    ui_blynkScreen.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_temporary_image.c
    fonts/ui_font_H1.c
    fonts/ui_font_minMedium.c
    fonts/ui_font_Number_big.c
    fonts/ui_font_Number_extra.c
    fonts/ui_font_Subtitle.c
    fonts/ui_font_Title.c)

add_library(ui ${SOURCES})
