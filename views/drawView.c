#include "drawView.h"
#include "Loading.h"

void drawRootView(windowModel *windowM)
{
    ClearBackground(TERTIARY);
    // if (windowM->isLoading) {
    //     float progress = windowM->loadingTime / 2.0f;
    //     if (progress > 1.0f) progress = 1.0f;
    //     LoadingScreen(windowM, progress);
    //     return;
    // }
    if (windowM->isLoading) {
        LoadingScreen(windowM, windowM->loadingTime / 2.0f);  
        return;
    }
    switch (windowM->currWindow)
    {
    case STAFHOME:
        drawHome(windowM);
        break;
    case PENGAJARHOME:
        drawPengajarHome(windowM);
        break;
    case MURIDHOME:
        drawMuridHome(windowM);
        break;
    case LOGINSTAFF:
        drawHeader(windowM);
        drawStaffLogin(windowM);
        break;
    case LOGINPENGAJAR:
        drawHeader(windowM);
        drawMuridTeacherLogin(windowM);
        break;
    case LOGINMURID:
        drawHeader(windowM);
        drawMuridTeacherLogin(windowM);
        break;
    case ADMINSTUDENT:
        break;
    case LANDINGPAGE:
        drawHeader(windowM);
        drawLandingPage(windowM);
        break;

    case CONTRIBPAGE:
        drawMemberPage(windowM);
        break;
    }
}