class BankAccount:
    def __init__(self, balance, name):
        self.balance = balance
        self.name = name

    def withdraw(self, amount):
        self.balance = self.balance - amount

    def deposit(self, amount):
        self.balance = self.balance + amount

smithAccount = BankAccount(10.0, 'Harriet Smith')

smithAccount.deposit(5.25)

print(smithAccount.balance)