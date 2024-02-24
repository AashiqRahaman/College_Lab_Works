# import pyautogui
# import time
# # Hi_I_am_Aashiq
# time.sleep(3)
# count = 0
# while count <= 500 :
#     pyautogui.typewrite("EVM")
#     pyautogui.hotkey('enter')
#     count = count + 1
    
import pyautogui
import time
# Hi_I_am_Aashiq_CSE_Student
comment_box_x = 257
comment_box_y = 927
# x,y psition depend on device
time.sleep(3)
pyautogui.moveTo(comment_box_x, comment_box_y)
count = 0

while count <= 1000 : 
    pyautogui.moveTo(comment_box_x, comment_box_y)
    pyautogui.click()
    time.sleep(0)
    pyautogui.typewrite("#EVM")
    pyautogui.hotkey('ctrl','enter')
    time.sleep(0)
    count = count + 1
    time.sleep(5)
    
