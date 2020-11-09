import matplotlib.pyplot as plt
import math

NSizes = [1000, 5000, 10000, 50000, 75000, 100000, 500000]
N = []
for i in NSizes:
    e = math.log(i, 10)
    N.append(e)
print(N)
selection = [0, 14, 44, 942, 2156, 3733, 93766]
insertion = [0, 3, 24, 340, 774, 1439, 37748]
merge = [0, 1, 2, 10, 16, 21, 115]
quick = [0, 0, 1, 4, 7, 9, 54]
hybrid = [0, 0, 0, 5, 7, 10, 58]

selection_inorder = [0, 13, 42, 968, 2227, 3849, 96371]
insertion_inorder = [0, 0, 0, 0, 0, 0, 0]
merge_inorder = [0, 1, 2, 6, 9, 13, 73]
quick_inorder = [0, 0, 0, 3, 3, 5, 27]
hybrid_inorder = [0, 0, 0, 0, 0, 0, 0]

# selection_reverse =
# insertion_reverse =
merge_reverse = [72, 78, 80, 143, 80, 85, 85]
quick_reverse = [27, 30, 29, 29, 29, 29, 29]

plt.plot(N, selection, 'o--b')
plt.plot(N, insertion, 'o--r', markersize=7)
plt.plot(N, merge, 'o--g', markersize=7)
plt.plot(N, quick, 'o--y')
plt.plot(N, hybrid, 'o--k')
plt.plot(N, selection_inorder, '*:b', markersize=7)
plt.plot(N, insertion_inorder, '*:r', markersize=7)
plt.plot(N, merge_inorder, '*:g', markersize=7)
plt.plot(N, quick_inorder, '*:y', markersize=7)
plt.plot(N, hybrid_inorder, '*:k', markersize=7)

plt.legend(["Selection", "insertion", "merge", "quick", "hybrid", "selection_inorder", "insertion_inorder",
            "merge_inorder", "quick_inorder", "hybrid_inorder"])
plt.show()


