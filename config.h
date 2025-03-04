/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */ 
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "UbuntuMono Nerd Font:size=12"};
static const char dmenufont[]       = "RobotoMono Nerd Font Mono:size=12";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char urgbgcolor[]           = "#222222";
static char urgbordercolor[]       = "#444444";
static char urgfgcolor[]           = "#bbbbbb";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
       [SchemeUrg]  = { urgfgcolor,  urgbgcolor,  urgbordercolor  },
};
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const Rule rules[] = {
  /* xprop(1):
   *  WM_CLASS(STRING) = instance, class
   *  WM_NAME(STRING) = title
   */
  /* class                   instance    title             tags mask     isfloating   monitor    float x,y,w,h         floatborderpx*/
  { "Blueman-manager",        NULL,       NULL,             0,            1,           -1,       50,50,500,500,        2 },
  { "Arandr",                 NULL,       NULL,             0,            1,           -1,       50,50,700,500,        2 },
  { "Gnome-calculator",       NULL,       NULL,             0,            1,           -1,       50,50,380,400,        2 },
  { "Gsimplecal",             NULL,       NULL,             0,            1,           -1,       50,50,250,100,        2 },
  { "Lxappearance",           NULL,       NULL,             0,            1,           -1,       50,50,600,400,        2 },
  { "Pavucontrol",            NULL,       NULL,             0,            1,           -1,       50,50,800,500,        2 },
  { "kitty",                  "kitty",		"scratchpad",     0,            1,           -1,       50,50,800,600,        2 },
  { "mpv",                    NULL,       "video0 - mpv",   0,            1,           -1,       1366,768,300,200,     2 },
  //{ "tabbed",                 NULL,       NULL,             0,            1,           -1,       50,50,500,500,        2 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *roficmd[] = {"rofi", "-show", "drun", "-show-icons", "-theme", "~/.cache/wal/colors-rofi-light.rasi", "-opacity=70", "-display-drun", " ", "-display-window", " ", "-display-run", " ", "-display-ssh", " "};

static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };

static const char *termcmd[]  = {"kittyStart.sh", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "kitty", "-T", scratchpadname, NULL };

//static const char *scratchpadcmd[] = { "tabbed", "-c", "-r", "2", "st", "-w", "''","-t", scratchpadname, "-g", "120x34", NULL };

#include <X11/XF86keysym.h>
/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
static char *statuscmds[] = { "volume", "microphone" , "memory", "forecast", "battery", "clock" };
static char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };

#include "movestack.c"
static Key keys[] = {
  /* type       modifier                      key        function        argument */
  { MODKEY,                       XK_d,      spawn,          {.v = roficmd } },
  { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
  { MODKEY,                       XK_b,      togglebar,      {0} },
  { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
  { MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = -1 } },
  { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
  { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
  { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
  { MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
  { MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
  { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,                       XK_f,      spawn,          SHCMD("thunar") },
  { MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
  { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_space,  setlayout,      {0} },
  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
  { MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
  { MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
  { MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
  { MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
  { MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
  { MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
  { MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
  { MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
  { MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
  { MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
  { MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
  { MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
  { MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
  { MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
  { MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
  { MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },
  { MODKEY,                       XK_s,      togglesticky,   {0} },
  { MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("killall screenkey || screenkey -s small &") },
  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  { MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
  { MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
  { MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
  { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
  TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_2,                      1)
  TAGKEYS(                        XK_3,                      2)
  TAGKEYS(                        XK_4,                      3)
  TAGKEYS(                        XK_5,                      4)
  TAGKEYS(                        XK_6,                      5)
  TAGKEYS(                        XK_7,                      6)
  TAGKEYS(                        XK_8,                      7)
  TAGKEYS(                        XK_9,                      8)
  { MODKEY|ShiftMask,             XK_e,      quit,           {0} },
  { MODKEY,                       XK_w,      spawn,           SHCMD("microsoft-edge") },
  { MODKEY,                       XK_x,      spawn,           SHCMD("slock") },
  { MODKEY,                       XK_c,      spawn,           SHCMD("code") },
  { MODKEY|ShiftMask,             XK_c,      spawn,           SHCMD("camtoggle.sh") },
  { MODKEY,                       XK_r,      spawn,           SHCMD("dmenurecord") },
  { MODKEY,                       XK_z,      spawn,           SHCMD("randomWallpaper.sh") },
  { MODKEY,                       XK_p,      spawn,           SHCMD("monitors.sh") },
  { MODKEY|ShiftMask,             XK_p,      spawn,           SHCMD("displaySelect.sh")},
  { 0,                            XK_Print,  spawn,           SHCMD("sleep 0.2; scrot -s ~/Pictures/scrot/%d_%m_%y_%H_%M_%S_scrot.png -e 'xclip -selection c -t image/png < $f'")},
  { ShiftMask,                    XK_Print,  spawn,           SHCMD("sleep 0.2; scrot ~/Pictures/scrot/%d_%m_%y_%H_%M_%S_scrot.png -e 'xclip -selection c -t image/png < $f'")},
  { 0, XF86XK_AudioMute,          spawn,    SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle; kill -44 $(pidof dwmblocks)") },
  { 0, XF86XK_AudioRaiseVolume,   spawn,    SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%; kill -44 $(pidof dwmblocks)") },
  { 0, XF86XK_AudioLowerVolume,   spawn,    SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%; kill -44 $(pidof dwmblocks)") },
  { 0, XF86XK_MonBrightnessUp,    spawn,    SHCMD("xbacklight -inc 5") },
  { 0, XF86XK_MonBrightnessDown,  spawn,    SHCMD("xbacklight -dec 5") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
  { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
  { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
  { ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
  { ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
  { ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
  { ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD("st -e vim ~/git/dwmblocks/config.h") },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

