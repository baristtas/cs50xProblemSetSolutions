from cs50 import get_float

owe = -1
# 0.25 0.10 0.05 0.01
if (owe < 0):
    owe = get_float("How much we owe to you baby?: ")

quarterCount = owe / 0.25
quarterCount = int(quarterCount)
owe = owe - (quarterCount * 0.25)

dimeCount = owe / 0.10
dimeCount = int(dimeCount)
owe = owe - (dimeCount * 0.10)

nickelCount = owe / 0.05
nickelCount = int(nickelCount)
owe = owe - (nickelCount * 0.05)

pennyCount = owe / 0.01
pennyCount = int(pennyCount)
owe = owe - (pennyCount * 0.01)

totalIronCount = quarterCount + dimeCount + nickelCount + pennyCount

print(totalIronCount)