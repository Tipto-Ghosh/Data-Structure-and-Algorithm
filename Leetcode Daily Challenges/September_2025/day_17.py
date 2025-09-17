from typing import List  
import heapq

class FoodRatings:
    
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        # food -> (cuisine , rating)
        self.food_info = {} 
        # for each cuisine also sort the highest rated food.(Max Heap)
        self.cuisine_heap = {} # cuisine -> maxHeap(-rating , food)
        
        for i in range(len(foods)):
            # get the food , cuisine , rating
            food , cuisine , rating = foods[i] , cuisines[i] , ratings[i]
            
            # store the food
            self.food_info[food] = (cuisine , rating)
            
            if cuisine not in self.cuisine_heap:
                # create a heap for this cuisine
                self.cuisine_heap[cuisine] = []
            # now store the rating and food in cuisine
            heapq.heappush(self.cuisine_heap[cuisine] , (-rating , food))
            
    def changeRating(self, food: str, newRating: int) -> None:
        # get the food info
        cuisine , prev_rating = self.food_info[food]
        # update the food info
        self.food_info[food] = (cuisine , newRating)
        
        # now update the rating in the cuisine
        heapq.heappush(self.cuisine_heap[cuisine] , (-newRating , food))
    
    def highestRated(self, cuisine: str) -> str:
        # find the highest rated food of this cuisine
        
        # take the current cuisines heap
        curr_cuisine_heap = self.cuisine_heap[cuisine]
        # now there can multiple entry for the same food with different rating.Take the lastest rating
        
        while curr_cuisine_heap:
            # get the top of the heap
            rating , food = curr_cuisine_heap[0]
            rating *= -1
            # check does rating is latest or not
            if rating == self.food_info[food][1]:
                return food # if latest the return the food 
            
            # if not latest then we dont need this rating anymore remove it
            heapq.heappop(curr_cuisine_heap)


