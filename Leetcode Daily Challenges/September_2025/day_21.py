from typing import List 
from collections import defaultdict
from sortedcontainers import SortedList , SortedSet

class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.available_movies = defaultdict(SortedList) # movie -> available (price , shop)
        self.movie_price = {} # (movie, shop) -> price
        self.rented_set = SortedSet() # rented movies: (price, shop, movie)
        
        for shop, movie, price in entries:
            self.available_movies[movie].add((price , shop))
            self.movie_price[(movie , shop)] = price

    def search(self, movie: int) -> List[int]:
        # return top-5 lowest shops than have `movie` available
        top_shops = []
        
        for price , shop in self.available_movies[movie]:
            top_shops.append(shop)
            if len(top_shops) == 5:
                break
        
        return top_shops
    
    def rent(self, shop: int, movie: int) -> None:
        # Move movie from available -> rented
        price = self.movie_price[(movie, shop)]
        self.rented_set.add((price, shop, movie))
        self.available_movies[movie].discard((price, shop))
         
    def drop(self, shop: int, movie: int) -> None:
        # Move movie from rented -> available
        price = self.movie_price[(movie, shop)]
        self.rented_set.discard((price, shop, movie))
        self.available_movies[movie].add((price, shop))
        
    def report(self) -> List[List[int]]:
        # Return up to 5 cheapest rented movies
        top_rented = []
        for price, shop, movie in self.rented_set:
            top_rented.append([shop, movie])
            if len(top_rented) == 5:
                break
        return top_rented