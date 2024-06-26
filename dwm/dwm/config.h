/* system tray config */
/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systraypinning = 0;   
/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayonleft = 0;    
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { 
	"JetBrains Mono Medium:size=13",
	"Font Awesome 6 Free Solid:size=13"
};
static const char dmenufont[]       = "JetBrains Mono Medium:size=13";
static const char col_gray1[]       = "#ffffff";
static const char col_gray2[]       = "#222222";
static const char col_gray3[]       = "#222222";
static const char col_gray4[]       = "#ffffff";
static const char col_cyan[]        = "#81a2be";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "xfreerdp",   NULL,       NULL,       1,             0,           -1 },
	{ "firefox",    NULL,       NULL,       1 << 1,        0,           -1 },
	{ "Chromium",   NULL,       NULL,       1 << 1,        0,           -1 },
	{ "Alacritty",  NULL,       NULL,       1 << 3,        0,           -1 },
	{ "Joplin",     NULL,       NULL,       1 << 4,        0,           -1 },
	{ "Pavucontrol",   
                    NULL,       NULL,       0,             1,           -1 },
	{ "thunderbird",  
                    NULL,       NULL,       1 << 8,        0,           -1 },
	{ "Rocket.Chat",     
                    NULL,       NULL,       1 << 5,        0,           -1 },
	{ "TelegramDesktop",     
                    NULL,       NULL,       1 << 5,        0,           -1 },
	{ "ONLYOFFICE Desktop Editors",     
                    NULL,       NULL,       1 << 7,        0,           -1 }
    
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 10;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "┇  ",      tile },    /* first entry is default */
	{ "┇  ",      NULL },    /* no layout function means floating behavior */
	{ "┇  [M]",     monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


#include <X11/XF86keysym.h>
#define XF86XK_AudioLowerVolume	0x1008FF11   /* Volume control down        */
#define XF86XK_AudioMute	0x1008FF12   /* Mute sound from the system */
#define XF86XK_AudioRaiseVolume	0x1008FF13   /* Volume control up          */
#define XF86XK_MonBrightnessUp   0x1008FF02  /* Monitor/panel brightness */
#define XF86XK_MonBrightnessDown 0x1008FF03  /* Monitor/panel brightness */


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = 
{ "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", 
    col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *brupcmd[] = { "sudo", "br_apple_th", "+", NULL };
static const char *brdowncmd[] = { "sudo", "br_apple_th", "-", NULL };
/*---FLAMESHOT---*/
static const char *flameshot_full_c[] = { "flameshot", "full", "-c", NULL };
static const char *flameshot_screen_c[] = { "flameshot", "gui", "-c", NULL };
/*---END_FLAMESHOT---*/

static Key keys[] = {
	/* modifier                     key        function        argument */

	{ MODKEY,                       XK_i,      view_adjacent,  { .i = +1 } },
	{ MODKEY,                       XK_u,      view_adjacent,  { .i = -1 } },
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_y,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
  	/* custom */
	{ 0,    XF86XK_AudioMute,   spawn,  SHCMD("pactl set-sink-mute 2 toggle && dunstvol") },
	{ 0,    XF86XK_AudioLowerVolume,    spawn,  SHCMD("pactl set-sink-volume 2 -3% && dunstvol") },
	{ 0,    XF86XK_AudioRaiseVolume,    spawn,  SHCMD("pactl set-sink-volume 2 +3% && dunstvol") },
	{ 0,    XF86XK_MonBrightnessUp,     spawn,  {.v = brupcmd} },
	{ 0,    XF86XK_MonBrightnessDown,   spawn,  {.v = brdowncmd} },
	{ MODKEY, XK_F2,                    spawn,  {.v = brupcmd} },
	{ MODKEY, XK_F1,                    spawn,  {.v = brdowncmd} },
    { 0,                XK_Print,   spawn,  SHCMD("flameshot full -p ~/Pictures/Full") },
    { ShiftMask,        XK_Print,   spawn,  {.v = flameshot_full_c} },
    { MODKEY,           XK_Print,   spawn,  SHCMD("flameshot gui -p ~/Pictures/Screen") },
    { MODKEY|ShiftMask, XK_Print,   spawn,  {.v = flameshot_screen_c} },
	/*{ 0,                XF86XK_LaunchB,      spawn,      {.v = flameshot} },*/
	{ 0, XK_F8,       spawn,      SHCMD("translate-text") },

	{ Mod1Mask,         XK_Shift_L, spawn,      SHCMD("ubar") },
	{ ShiftMask,        XK_Alt_L,   spawn,      SHCMD("ubar") },
	{ MODKEY|ShiftMask, XK_r,       spawn,      SHCMD("restartdwm") }
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
/*	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} }, */
	{ ClkWinTitle,          0,              Button2,        killclient,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
