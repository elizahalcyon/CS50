class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError('Wrong Capacity')
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return self.size * '🍪'

    def deposit(self, n):
        if n > self.capacity:
            raise ValueError('Capacity Exceeded')
        if self.size + n > self.capacity:
            raise ValueError('Capacity Exceeded')
        self._size += n

    def withdraw(self, n):
        if n > self.size:
            raise ValueError('Not enough cookies')
        self._size -= n



    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

main()
jar = Jar()
jar.deposit(2)
jar.withdraw(1)
print(jar)
print(str(jar.capacity))