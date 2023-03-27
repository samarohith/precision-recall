s=("bzr" "p53" "aids" "muta")
c=(96 97 98 99 100)

for d in ${s[@]}; do 
    for n in ${c[@]};
        do ./sub $d $n;
    done;
done;

