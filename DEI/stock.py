
t = int(input())
inputs = []
frases = []

for i in range(t):
    inputs.append(int(input()))
    frases.append(list())
    for j in range(inputs[i]):
        frases[i].append(input())

for i in range(t):
    
    buy = []
    sell = []
    stock = -1

    for j in range(inputs[i]):

        s = frases[i][j].split()
        vals = (int(s[1]), int(s[4]))

        if s[0] == "buy":
            
            buy.append(vals)
            buy.sort(key=lambda x:x[1], reverse=True)
            
        elif s[0] == "sell":

            sell.append(vals)
            sell.sort(key=lambda x:x[1], reverse=False)

        bid = -1 if len(buy) == 0 else buy[0][1]
        ask = -1 if len(sell) == 0 else sell[0][1]

        while(bid >= ask and (bid != -1 and ask != -1)):
            stock = ask

            v = min(buy[0][0], sell[0][0])
            vBuy = buy[0][0] - v
            vPriceBuy = buy[0][1]
            vSell = sell[0][0] - v
            vPriceSell = sell[0][1]

            del buy[0]
            del sell[0]
            buy.insert(0, (vBuy, vPriceBuy))
            sell.insert(0, (vSell, vPriceSell))

            if(buy[0][0] == 0):
                del buy[0]

            if(sell[0][0] == 0):
                del sell[0]

            bid = -1 if len(buy) == 0 else buy[0][1]
            ask = -1 if len(sell) == 0 else sell[0][1]

        strAsk = ("-" if ask == -1 else str(ask)) + " " 
        strBid = ("-" if bid == -1 else str(bid)) + " "
        strStock = "-" if stock == -1 else str(stock)

        print(strAsk + strBid + strStock)



