#include<iostream>
#include "StackArrLL.hpp"
#include "QueueArrLL.hpp"
using namespace std;
int main()
{
    freopen("test2.txt", "r", stdin);
    freopen("test2_out.txt", "w", stdout);
    int n, c, x, y, player1 = 0, player2 = 0, waste = 0, j = 0, s1, s2, sp1, sp2, temp, ind1=0, ind2=0;
    cin >> n >> c;
    int *a = new int[n]{0};
    int *b = new int[n]{0};
    int sa[n], spa[n];
    MyList<int> *start = new LL<int>(n);
    MyList<int> *span = new LL<int>(n);
    Queue<int> *line1 = new QueueArr<int>;
    Queue<int> *seq1 = new QueueArr<int>;
    Stack<int> *line2 = new StackArr<int>;
    Stack<int> *seq2 = new StackArr<int>;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        sa[i]=x;
        spa[i]=y;
        b[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
           if(sa[i]>sa[j])
           {
              swap(sa[i],sa[j]);
              swap(spa[i],spa[j]);
              swap(b[i],b[j]);
           }
        }
    }
    if(sa[0]==0)
    {
        ind1=1;
        c++;
        for(int i=0; i<n; i++)
        {
            sa[i]++;
        }
    }
    for(int i=0; i<n; i++)
    {
        start->pushBack(sa[i]);
        span->pushBack(spa[i]);
    }
    start->setToBegin();
    span->setToBegin();
    
    for (int i = 1; i <= c; i++)
    {
        while (i == player1)
        {
            if (line1->length())
            {
                if (player1 > c)
                {
                    a[seq1->dequeue()] = -1;
                    player1 += line1->dequeue();
                    continue;
                }
                else if (player1 == c && line1->frontValue() > 0 && line1->length())
                {
                    a[seq1->dequeue()] = -1;
                    player1 += line1->dequeue();
                    continue;
                }
                player1 += line1->dequeue();
                if (player1 > c)
                    player1 = c;
                a[seq1->dequeue()] = player1;
            }
            else
                player1 = 0;
        }
        while (i == player2)
        {
            if (start->getValue() == player2 && line1->length()>=3) //
            {
                if (player2 > c)
                {
                    a[j] = -1;
                    player2 = start->erase() + span->erase();
                }
                else if (player2 == c && span->getValue() > 0)
                {

                    a[j] = -1;
                    player2 = start->erase() + span->erase();
                }
                else
                {
                    player2 = start->erase() + span->erase();
                    a[j] = player2;
                }
                j++;
                continue;

            } //
            if (line2->length())
            {
                if (player2 >= c)
                {
                    a[seq2->pop()] = -1;
                    player2 += line2->pop();
                    continue;
                }
                else if (player2 == c && line2->topValue() > 0 && line2->length())
                {

                    a[seq2->pop()] = -1;
                    player2 += line2->pop();
                    continue;
                }
                player2 += line2->pop();
                if (player2 > c)
                    player2 = c;
                a[seq2->pop()] = player2;
            }
            else
                player2 = 0;
        }
        while (i == start->getValue())
        {
            if (player1 == 0)
            {

                if (player1 > c)
                {
                    a[j] = -1;
                    player1 = start->erase() + span->erase();
                    j++;
                    continue;
                }
                else if (player1 == c && span->getValue() > 0)
                {

                    a[j] = -1;
                    player1 = start->erase() + span->erase();
                    j++;
                    continue;
                }
                player1 = start->erase() + span->erase();
                if (player1 > c)
                    player1 = c;
                a[j] = player1;
            }
            else if (line1->length() < 3)
            {
                waste = start->erase();
                line1->enqueue(span->erase());
                seq1->enqueue(j);
            }
            else
            {
                if (player2 == 0)
                {
                    if (player2 > c)
                    {
                        a[j] = -1;
                        player2 = start->erase() + span->erase();
                        j++;
                        continue;
                    }
                    else if (player2 == c && span->getValue() > 0)
                    {

                        a[j] = -1;
                        player2 = start->erase() + span->erase();
                        j++;
                        continue;
                    }
                    player2 = start->erase() + span->erase();
                    if (player2 > c)
                        player2 = c;
                    a[j] = player2;
                }
                else
                {
                    waste = start->erase();
                    line2->push(span->erase());
                    seq2->push(j);
                }
            }
            if (i == player1)
            {
                if (line1->length())
                {
                    if (player1 > c)
                    {
                        a[seq1->dequeue()] = -1;
                        player1 += line1->dequeue();
                        continue;
                    }
                    else if (player1 == c && line1->frontValue() > 0 && line1->length())
                    {
                        a[seq1->dequeue()] = -1;
                        player1 += line1->dequeue();
                        continue;
                    }
                    player1 += line1->dequeue();
                    if (player1 > c)
                        player1 = c;
                    a[seq1->dequeue()] = player1;
                }
                else
                    player1 = 0;
            }
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1 && a[i] != 0)
            cout << i + 1 << ">" <<  a[i]-ind1 << endl;
        else
            cout << i + 1 << ">c" << endl;
    }

    delete b;
    delete a;
    delete start;
    delete span;
    delete line1;
    delete seq1;

    delete line2;
    delete seq2;
}