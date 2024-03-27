# import pyautogui
# import time
# # Hi_I_am_Aashiq_CSE_Student
# time.sleep(3)
# count = 0

# while count <= 1 : 
#     pyautogui.typewrite("abc")
#     pyautogui.hotkey('enter')
#     count = count + 1
#     time.sleep(0)
    
# while count <= 1 : 
#     pyautogui.typewrite("abc")
#     pyautogui.hotkey('enter')
#     count = count + 1
#     time.sleep(0)


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
comment_box_x = 1497
comment_box_y = 599
# x,y psition depend on device
time.sleep(3)
pyautogui.moveTo(comment_box_x, comment_box_y)
count = 0

while count <= 100 : 
    pyautogui.moveTo(comment_box_x, comment_box_y)
    pyautogui.click()
    time.sleep(0)
    pyautogui.typewrite("#WE_WANT_SUGGESTION #CR_PLEASE_TALK_TO_TEACHER")
    pyautogui.hotkey('enter')
    time.sleep(0)
    count = count + 1
    time.sleep(1)
    
