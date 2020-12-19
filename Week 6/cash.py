from cs50 import get_float

owe = -1
# 0.25 0.10 0.05 0.01

if (owe < 0):
    owe = get_float("How much we owe to you baby?: ")
owe = owe * 100
quarterCount = owe / 25
quarterCount = int(quarterCount)
owe = owe - (quarterCount * 25)

dimeCount = owe / 10
dimeCount = int(dimeCount)
owe = owe - (dimeCount * 10)

nickelCount = owe / 5
nickelCount = int(nickelCount)
owe = owe - (nickelCount * 5)

pennyCount = owe / 1
pennyCount = int(pennyCount)
owe = owe - (pennyCount * 1)

totalIronCount = quarterCount + dimeCount + nickelCount + pennyCount

print(totalIronCount)