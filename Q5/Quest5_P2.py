import sys

def fishbone_quality(nums):
    spine = [{"val": nums[0], "left": None, "right": None}]
    for num in nums[1:]:
        placed = False
        for segment in spine:
            if num < segment["val"] and segment["left"] is None:
                segment["left"] = num
                placed = True
                break
            elif num > segment["val"] and segment["right"] is None:
                segment["right"] = num
                placed = True
                break
        if not placed:
            spine.append({"val": num, "left": None, "right": None})
    return int("".join(str(seg["val"]) for seg in spine))

lines = sys.stdin.read().strip().splitlines()

qualities = []

for s in lines:
    if not s.strip():
        continue
    id, nb = s.split(":")
    nums = list(map(int, nb.split(',')))
    q = fishbone_quality(nums)
    qualities.append(q)

diff = max(qualities) - min(qualities)
print(diff)
