
from abc import ABC, abstractmethod

class Animal(ABC):
    """"""

    @abstractmethod
    def move(self): pass

    @abstractmethod
    def f1(self): pass

class Dog(Animal):
    """"""
    def move(self):
        print("I am a dog")

    def f1(self):
        print("Inside Dog.f1")
