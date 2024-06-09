#! /bin/env lua
local poptrans =
{
    -- select language from lang to lang
    lang_from = "auto", --auto,en,fr,de or other
    lang_to   = "ru",
    -- copy translated text to clipboard
    -- if you select text (no use context menu textcopy)
    --   - middle mouse button paste translated text
    --   - right mouse button context menu paste original text
    --   - script used 2 levels X11 clipboard buffest of 3 levels :)
    copy_translated = true,
    -- how more seconds show you translated text
    show_timer = 3,
    -- popup translated text under mouse position
    follow_mouse = true,
    -- if follow_moise is false, set translated
    -- text position static coords
    popup_pose_x = 0,
    popup_pose_y = 0,
    -- max width message in screen, zero is auto
    popup_width  = 0,
    -- get text from system clipboard
    app_clipboard = "xclip -o 2> /dev/null",
    -- set text to system clipboard
    app_set_clipb = "xsel -b -i ",
    -- get mouse systemd coords
    app_mousepose = "xdotool getmouselocation 2> /dev/null",
    -- show text popup with translated text
    app_popup_msg = "aosd_cat -x %d -y %d -B white -R white -t 0 -p 0 -u %d -w %d -n 'Arial Black 30'"
}

function poptrans:run()
    local translated = '';
    self.previos_text = '';
    -- read clipboard
    local exec = io.popen(self.app_clipboard);
    local text = exec:read('*all');exec:close();
    -- get cursor position
    exec = io.popen(self.app_mousepose);
    if self.follow_mouse then
        self.popup_pose_x,self.popup_pose_y = exec:read("*all"):match("x:(%d+) y:(%d+)");
        self.popup_pose_x = self.popup_pose_x+3; exec:close();
    end
    -- do not translate previos text or empty or translated text
    if text ~= previos_text and text ~= '' and text ~= translated then
      local from = ''
      if self.lang_from ~= "auto" then
        from = self.lang_from;
      end
      exec = io.popen('trans   '..from..':'..self.lang_to.." -b '"..text.."'");
      translated = exec:read("*all"); exec:close();
      if self.copy_translated then
         exec = io.popen(self.app_set_clipb,'w')
         exec:write(translated:sub(1,#translated-1));
         exec:flush();
         exec:close();
      end
      previos_text = text;
      exec = io.popen(
      self.app_popup_msg:format(
      self.popup_pose_x,self.popup_pose_y,self.show_timer*1000,self.popup_width),"w");
      exec:write(translated);exec:close();
    end
end

poptrans:run()
