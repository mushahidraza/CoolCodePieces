import os
import sys

#TASK 3 FUNCTIONS TO BE USED LATER

def CalculateFamilyPrice(adults,children,seniors,dayType):
    ticketCount = 0
    ineligible = False 
    rate = sys.maxsize #MAXIMUM POSSIBLE NUMBER LIKE 999999999999
    guardians = adults + seniors
    while (guardians > 0 and children > 0 and ineligible == False):
        ticketCount = ticketCount + 1
        guardians = guardians - 2
        children = children - 3

        if (children <= 0 and guardians > 0):
            ineligible = True
    #End While

    if ineligible == False:
        if (dayType == 1):
            rate = ticketCount * 60
        else:
            rate = ticketCount * 90
    
    return rate, ticketCount
    

def CalculateGroupPrice(adults,children,seniors,dayType):
    rate = sys.maxsize #MAXIMUM POSSIBLE NUMBER LIKE 999999999999
    people = adults + seniors + children 
    if (people >= 6):
        if (dayType == 1):
            rate = people * 15
        else:
            rate = people * 22.5
    return rate

#END OF TASK 3 FUNCTIONS


#--------------------------------------------------------------------------------------------------
#TASK 1
ticket_type = ["One Adult",
               "One Child",
               "One Senior", 
               "Family Ticket",
               "Group Ticket(Per Person)"]

cost_one_day = [20,12,16,60,15]

cost_two_day = [30,18,24,90,22.5]

extra_attracts = ["Lion feeding",
                    "Penguin feeding", 
                    "Evening barbecue (Two-Day Tickets Only)"]
att_cost = [2.5,2,5]

valid_days = []

#ONE DAY DETAILS
print("TICKET PRICE FOR ONE-DAY:")
for i in range (len(ticket_type)):
    print(ticket_type[i],": $%.2f"% cost_one_day[i])
    
#TWO DAY DETAILS
print("\nTICKET PRICE FOR TWO-DAY:")
for i in range (len(ticket_type)):
    print(ticket_type[i],": $%.2f"% cost_two_day[i])

#EXTRA ATTRACTIONS    
print("\nEXTRA ATTRACTION PRICE:")
for i in range (len(extra_attracts)):
    print(extra_attracts[i],": $%.2f"% att_cost[i])

    
#VALID DAYS
day = int(input("\nEnter Today's day (1-31): "))
while (day < 1 or day > 31):    #VALIDATION CHECK ON DATE
    day = int(input("Enter today's day (1-31): "))

startday = day 
valid_days.append(startday)
for i in range(6):    #7 days in week excluding 0
    if(day == 31):  #checking if the end of the day
        day = 0     #set the day back to 0 as new month has started

    day = day + 1   #incrementing the days
    valid_days.append(day)

print("\nTickets are available for the following days: ")
print(valid_days)

bookingday = int(input("\nEnter a valid booking day from above: "))
while(True): #Validation Check on Day
    if bookingday not in valid_days:
        bookingday = int(input("Enter a booking day available above: "))
    else:
        break

#END OF TASK 1
#--------------------------------------------------------------------------------------------------                 

#--------------------------------------------------------------------------------------------------
#TASK 2

booking_no = int()
choice_no = int()
adult,child,senior = int(),int(),int()
ticket_price = float()
attraction_price = float()
booking_choice = str()
extra_choice = str()
tickets = [None,None,None] # Adult, child, senior
attractions = [None,None,None] #lion,penguin,bbq

booking_choice = input("\n\nDo you want to make a Booking? Y/N\nYour Choice: ")
while (booking_choice == 'Y' or booking_choice == 'y'): #Validation check on Y or N
    booking_no += 1
    
    tickets = [0,0,0] # Adult, child, senior
    attractions = [0,0,0] #lion,penguin,bbq
    adult,child,senior = 0,0,0

    while(1):
        day_choice = int(input("Press 1 For 1-Day Booking\nPress 2 For 2-Day Booking:\nYour Choice: "))
        if(day_choice == 1 or day_choice == 2): #Validation Check on day choice
            break
    #END WHILE
    
    os.system('cls')
    adult = int(input("Enter no. of Adults: "))
    child = int(input("Enter no. of Children: "))
    senior = int(input("Enter no. of Seniors: "))
    
    while(child / (adult+senior) > 2):  #Validation Check on Children and Adults
        print("Error: Only 2 children per adult allowed")
        adult = int(input("Enter no. of Adults: "))
        child = int(input("Enter no. of Children: "))
        senior = int(input("Enter no. of Seniors: "))
    #END WHILE
    
    os.system('cls')
    tickets[0] = adult
    tickets[1] = child
    tickets[2] = senior
    
    extra_choice = input("Do you want Extra Attractions? Y/N\nYour Choice: ")
    os.system('cls')
    while(extra_choice == 'Y' or extra_choice == 'y'): #Validation Check
        print('Press 1 for Lion Feeding')
        print('Press 2 for Penguin Feeding')
        print('Press 3 for Evening Barbecue')
        
        choice_no = int(input("Your Choice: "))
        
        
        if(attractions[choice_no-1] == 1):
            print("Attraction Already Selected!")
        
        elif(choice_no == 3 and day_choice == 1):
            print("BBQ is only available for 2-Day Booking")
            
        else:
            attractions[choice_no-1] = 1

              
        if (attractions[0] == 1 and attractions[1] == 1 and day_choice == 1):
            break

        elif 0 not in attractions:
            break
    
        extra_choice = input("Do you want more Extra Attractions? Y/N: ")
    #END WHILE
    
    os.system('cls')
    ticket_price = 0
    attraction_price = 0
    if(day_choice == 1):
        for i in range (len(tickets)):
                ticket_price += tickets[i] * cost_one_day[i]
                attraction_price += (tickets[i] * attractions[0] * att_cost[0] + tickets[i] * attractions[1] * att_cost[1]) 
    else:
        for i in range (len(tickets)):
                ticket_price += tickets[i] * cost_two_day[i]
                attraction_price += (tickets[i] * attractions[0] * att_cost[0] + tickets[i] * attractions[1] * att_cost[1] + tickets[i] * attractions[2] * att_cost[2])
    
    #PRINTING DETAILS
    print("Booking No.", booking_no)
    print("Ticket Price:", ticket_price)
    print("Extra Attraction Price:", attraction_price)
    print ("Grand Total:", (ticket_price + attraction_price))
#----------------------------------------------------------------------------------------------
#TASK 3 STARTED

    #TASK 3 IS IMPLEMENTED INSIDE TASK 2

    #CALCULATING THE FAMILY TICKET AND GROUP TICKET PRICE
    family_rate,tic_count = CalculateFamilyPrice(tickets[0],tickets[1],tickets[2],day_choice)
    group_rate = CalculateGroupPrice(tickets[0],tickets[1],tickets[2],day_choice)
    
    
    #IF FAMILY TICKET OFFERS THE BEST PRICE
    if(ticket_price > family_rate and group_rate > family_rate):
        print ("\nBEST")
        print("Family Tickets:\nPrice:",family_rate,"- by buying",tic_count,"Family Tickets")
        print("Save on Ticket Price:",ticket_price - family_rate)
        offer_choice = input ("Do you want to take this offer? (Y/N): ")
        if (offer_choice == 'y' or offer_choice == 'Y'):
            ticket_price = family_rate  #PRICE SWITCHED WITH NEW

            #PRINTING DETAILS
            print("Booking No.", booking_no)
            print("Ticket Price:", ticket_price)
            print("Extra Attraction Price:", attraction_price)
            print ("Grand Total:", (ticket_price + attraction_price))
            
    #IF GROUP RATE OFFERS THE BEST PRICE
    elif (ticket_price > group_rate and family_rate > group_rate):
        print ("\nBEST OFFER:")
        print("Group Tickets:\nPrice:",group_rate)
        print("Save on Ticket Price:",ticket_price - group_rate)
        offer_choice = input ("Do you want to take this offer? (Y/N): ")
        if (offer_choice == 'y' or offer_choice == 'Y'):
            ticket_price = group_rate # PRICE SWITCHED WITH NEW

            #PRINGTING DETAILS
            print("Booking No.", booking_no)
            print("Ticket Price:", ticket_price)
            print("Extra Attraction Price:", attraction_price)
            print ("Grand Total:", (ticket_price + attraction_price))
    
    #INCASE NO OTHER OFFER IS PRESENT
    else:
        print("No Special Offers For You Right Now...")
#----------------------------------------------------------------------------------------------
#TASK 3 ENDED
    #CONITNUING THE LOOP
    booking_choice = input("Do you want to make another Booking? Y/N\nYour Choice: ")
    os.system('cls')
#END WHILE


#END OF TASK 2
#--------------------------------------------------------------------------------------------------