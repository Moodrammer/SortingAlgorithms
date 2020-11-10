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
hybrid = [0, 0, 0, 4, 6, 9, 53]

selection_inorder = [0, 13, 42, 968, 2227, 3849, 96371]
insertion_inorder = [0, 0, 0, 0, 0, 0, 0]
merge_inorder = [0, 1, 2, 6, 9, 13, 73]
quick_inorder = [0, 0, 0, 3, 3, 5, 27]
hybrid_inorder = [0, 0, 0, 0, 0, 0, 0]

selection_reverse = [0, 13, 81, 1001, 2266, 4026, 96938]
insertion_reverse = [0, 14, 53, 726, 1666, 3380, 81979]
merge_reverse = [0, 1, 2, 12, 10, 13, 75]
quick_reverse = [0, 0, 0, 3, 4, 8, 29]
hybrid_reverse = [0, 0, 0, 3, 4, 5, 29]

selection_nearly = [0, 12, 51, 977, 2221, 3872, 98399]
insertion_nearly = [0, 0, 0, 0, 0, 0, 1]
merge_nearly = [0, 1, 1, 7, 14, 19, 75]
quick_nearly = [0, 0, 0, 3, 4, 5, 27]
hybrid_nearly = [0, 0, 0, 0, 0, 0, 1]

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

# plt.plot(N, selection_reverse, '1-b', markersize=7)
# plt.plot(N, insertion_reverse, '1-r', markersize=7)
# plt.plot(N, merge_reverse, '1-g', markersize=7)
# plt.plot(N, quick_reverse, '1-y', markersize=7)
# plt.plot(N, hybrid_reverse, '1-k', markersize=7)
#
# plt.plot(N, selection_nearly, '2--b', markersize=7)
# plt.plot(N, insertion_nearly, '2--r', markersize=7)
# plt.plot(N, merge_nearly, '2--g', markersize=7)
# plt.plot(N, quick_nearly, '2--y', markersize=7)
# plt.plot(N, hybrid_nearly, '2--k', markersize=7)

# plt.legend(["Selection", "insertion", "merge", "quick", "hybrid", "selection_inorder", "insertion_inorder",
#             "merge_inorder", "quick_inorder", "hybrid_inorder", "selection_reverse", "insertion_reverse",
#             "merge_reverse", "quick_reverse", "hybrid_reverse", "selection_nearly", "insertion_nearly",
#             "merge_nearly", "quick_nearly", "hybrid_nearly"])
plt.legend(["Selection", "insertion", "merge", "quick", "hybrid", "selection_inorder", "insertion_inorder",
            "merge_inorder", "quick_inorder", "hybrid_inorder"])
plt.show()



