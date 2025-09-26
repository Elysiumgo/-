/*2452545 计算机 刘晴语*/
#include <iostream>
#include <cstring>
#include <conio.h>
#include "cmd_console_tools.h"
#include "7-b2.h"

using namespace std;



static void safe_truncate(char* dest, const char* src, int max_display_width) {
    int src_pos = 0;
    int dest_pos = 0;
    int display_width = 0;

    while (display_width < max_display_width && src[src_pos] != '\0') {
        bool is_wide = (unsigned char)src[src_pos] >= 0x80;
        int char_width = is_wide ? 2 : 1;

        if (display_width + char_width > max_display_width) {
            // 处理窗口边界换行情况
            if (max_display_width % 2 == 0 && is_wide) {
                // 奇数宽度遇到宽字符，留一个空格
                dest[dest_pos++] = ' ';
                display_width++;
            }
            break;
        }
        //我的奇数字符宽度一直错位我处理不好

        if (is_wide) {
            dest[dest_pos++] = src[src_pos++];
            dest[dest_pos++] = src[src_pos++];
        } else {
            dest[dest_pos++] = src[src_pos++];
        }
        display_width += char_width;
    }
    dest[dest_pos] = '\0';
}






static void draw_menu(const char menu[][MAX_ITEM_LEN], const PopMenu* para, int start_idx, int selected_idx) {
    
    int actual_width = para->width;
    if (actual_width % 2 != 0) actual_width++;  
    actual_width = max(actual_width, (int)strlen(para->title) + 2); // 不小于标题长度


    // 计算菜单项数
    int item_count = 0;
    while (item_count < MAX_ITEM_LEN && menu[item_count][0] != '\0') {
        item_count++;
    }

    // 计算显示高度

    int display_height = min(para->high, item_count);



    // 边框
    cct_setcolor(para->bg_color, para->fg_color);

    // 上边框
    cct_gotoxy(para->start_x, para->start_y + 1);
    cout << "┏";
    for (int i = 0; i < actual_width; i++) cout << "━";
    cout << "┓ ";

    // 标题行（居中）
    int title_len = 0;
    const char* p = para->title;
    while (*p) {
        title_len += ((*p & 0x80) ? 2 : 1); // 计算实际显示长度
        p += ((*p & 0x80) ? 2 : 1);
    }




    // 居中显示标题
    int title_pos = (actual_width - title_len) / 2;
    cct_gotoxy(para->start_x  + title_pos, para->start_y + 1);
    cout << ' ';
    cct_gotoxy(para->start_x + 1 + title_pos, para->start_y + 1);
    cout << para->title;



    // 菜单项
    char display_buf[MAX_ITEM_LEN + 2] = { 0 };
    for (int i = 0; i < display_height; i++) {
        int item_idx = start_idx + i;

        // 左侧边框
        cct_gotoxy(para->start_x, para->start_y + 2 + i);
        cout << "┃";

        // 菜单
        int content_width = actual_width - 2;

        safe_truncate(display_buf, menu[start_idx + i], content_width);
        // 显示选中项
        cct_setcolor((item_idx == selected_idx) ? para->fg_color : para->bg_color,
            (item_idx == selected_idx) ? para->bg_color : para->fg_color);

        cct_gotoxy(para->start_x + 1, para->start_y + 2 + i);
        cout << display_buf;

        // 右侧边框
        for (int j = strlen(display_buf); j < actual_width; j++) 
            cout << " ";

        cct_setcolor(para->bg_color, para->fg_color);
        cct_gotoxy(para->start_x + actual_width + 1, para->start_y + 2 + i);
        cout << "┃ ";
    }

    // 下边框
    cct_gotoxy(para->start_x, para->start_y + display_height + 2);
    cout << "┗";
    for (int i = 0; i < actual_width; i++) cout << "━";
    cout << "┛ ";
}




// 主菜单函数
int pop_menu(const char menu[][MAX_ITEM_LEN], const PopMenu* para) {
    
    if (!menu || !para)
        return 0;

    // 计算菜单项数
    int item_count = 0;
    while (item_count < MAX_ITEM_LEN && menu[item_count][0] != '\0') {
        item_count++;
    }
    if (item_count == 0)
        return 0;




   

    // 计算实际高度
    int display_height = min(para->high, item_count);
    if (display_height <= 0) 
        return 0;
    // 初始化
    int selected_idx = 0;
    int start_idx = 0;
    





    cct_setcursor(CURSOR_INVISIBLE);

    
    draw_menu(menu, para, start_idx, selected_idx);

    // 输入处理
    while (true) {
        int MX, MY, MAction, keycode1, keycode2;
        int event_type = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);

        if (event_type == CCT_KEYBOARD_EVENT) {
            int old_selected_idx = selected_idx;
            int old_start_idx = start_idx;
            bool state_changed = false;

            if (keycode1 == 0xE0) {  // 方向键
                switch (keycode2) {
                case KB_ARROW_UP:
                    if (selected_idx > 0) {
                        selected_idx--;
                        state_changed = true;
                    }
                    break;
                case KB_ARROW_DOWN:
                    if (selected_idx < item_count - 1) {
                        selected_idx++;
                        state_changed = true;
                    }
                    break;
                }
            }
            else if (keycode1 == '\r') {
                return selected_idx + 1;
            }
            else if (keycode1 == 27) {
                return 0;
            }

            
            if (state_changed) {
                
                if (selected_idx < start_idx) {
                    start_idx = selected_idx;
                }
                else if (selected_idx >= start_idx + display_height) {
                    start_idx = selected_idx - display_height + 1;
                }
            }

            
            if (start_idx != old_start_idx || selected_idx != old_selected_idx) {
                draw_menu(menu, para, start_idx, selected_idx);
            }
        }
    }
}





