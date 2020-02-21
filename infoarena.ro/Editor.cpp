#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>

using namespace std;
char commands[60006];
char processedCommands[60006];
int numberOfCommands=0;
stack<char> paranthesisStack;
bool ok;

int main() {
    freopen("editor.in","r",stdin);
    freopen("editor.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    for(int index=1;index<=n;++index) {
        while(!paranthesisStack.empty()) paranthesisStack.pop();
        ok=0;
        numberOfCommands=0;
        memset(commands,0, sizeof(commands));
        memset(processedCommands,0, sizeof(processedCommands));
        cin>> commands;
        for(int i=0;commands[i]!='E';++i) {
            if(commands[i]=='*') {
                if(numberOfCommands)
                    numberOfCommands--;
                continue;
            }
            if(commands[i]=='E')
                break;
            processedCommands[++numberOfCommands]=commands[i];
        }
        if(numberOfCommands%2)
        {
            printf(":(\n");
            continue;
        }
        for(int i=1;i<=numberOfCommands;++i) {
            if(processedCommands[i]=='(' || processedCommands[i]=='[')
                paranthesisStack.push(processedCommands[i]);
            else {
                if(processedCommands[i]==')') {
                    if(!paranthesisStack.empty() && paranthesisStack.top()=='(') {
                        paranthesisStack.pop();
                    } else
                    {
                        printf(":(\n");
                        ok=1;
                        break;
                    }

                } else {
                    if(processedCommands[i]==']') {
                        if(!paranthesisStack.empty() && paranthesisStack.top()=='[') {
                            paranthesisStack.pop();
                        } else
                        {
                            printf(":(\n");
                            ok=1;
                            break;
                        }

                    }
                }
            }
        }
        if(ok)
            continue;
        if(!paranthesisStack.empty()) {
            printf(":(\n");
        } else {
            printf(":)\n");
        }

    }
    return 0;
}