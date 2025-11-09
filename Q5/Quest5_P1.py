import sys

s = sys.stdin.read().strip()
id, nb = s.split(":")
nums = list(map(int, nb.split(',')))

spine = [{"val": nums[0], "left": None, "right": None}]

for num in nums[1:]:
    placed = False
    for segment in spine:
        if (num < segment["val"] and segment["left"] is None):
            segment["left"] = num
            placed = True
            break
        elif (num > segment["val"] and segment["right"] is None):
            segment["right"] = num
            placed = True
            break
    if not placed:
        spine.append({"val": num, "left": None, "right": None})

spine_quality = "".join(str(seg["val"]) for seg in spine)
print(spine_quality)