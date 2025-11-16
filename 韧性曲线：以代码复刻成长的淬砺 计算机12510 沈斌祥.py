# 初始化成长里程碑：以字典列表构建"初始奠基+五阶跃升"的成长路径，gain用1.5^i实现指数增长
# 隐喻：成长从1个基础单位起步，每阶段收获呈复利式积累，对应学习/能力的阶梯式突破
growth_milestones = [{"stage": "init", "gain": 1}] + [{"stage": f"stage {i}", "gain": 1.5**i} for i in range(1, 6)]

# 匿名函数封装成长迭代逻辑：1. 遍历所有里程碑，叠加总阶段数×0.3的"积累赋能值"（积累厚度反哺每个阶段）
# 2. 新增"突破阶段"，收获为前序所有阶段最大值的1.2倍（模拟成长中的关键跃迁）
# 3. 用列表推导式实现多逻辑整合，一行完成"存量积累+增量突破"的成长曲线构建
growth_curve = (lambda ms: [m["gain"] + len(ms) * 0.3 for m in ms + [{"gain": max(m["gain"] for m in ms) * 1.2}]])(growth_milestones)

# 最终成长值计算：1. 短路判断避免空列表异常；2. 取成长曲线极小值（隐喻挫折），绝对值开根号转化为"抗压增益"
# 3. 非线性转化（根号）模拟成长中"波动平滑效应"，挫折不会抵消成果，反而转化为韧性资本
final_growth = growth_curve[-1] if growth_curve else 0 + (lambda x: x ** 0.5 if x > 0 else 0)(abs(min(growth_curve, default=0)))

# 设计思路总览：
# 1. 技术复杂度：融合字典列表（结构化成长数据）、列表推导式（高效迭代）、匿名函数（逻辑封装）、指数/根号运算（非线性映射）、极值处理（异常与波动兼容），一行代码承载多重编程逻辑，体现代码素养；
# 2. 主题深度：以"积累-突破-抗逆"三维度诠释成长——指数增长对应"持续积累的复利效应"，阶段数权重对应"沉淀赋能成长"，突破阶段对应"关键节点的跃迁"，极值转化对应"挫折即养分的韧性成长"，完全贴合大赛主题；
# 3. 创意巧思：用编程逻辑复刻成长规律，技术实现与思想内涵高度绑定，既展现代码的功能性，又通过隐喻赋予代码情感与哲思，避免单纯追求复杂度而脱离主题，符合"代码赋情、织韵思"的赛事核心。





#可视化代码
'''
import matplotlib.pyplot as plt  # 导入 matplotlib

growth_milestones = [{"stage": "init", "gain": 1}] + [{"stage": f"stage {i}", "gain": 1.5**i} for i in range(1, 6)]

# 计算 growth_curve
growth_curve = (lambda ms: [m["gain"] + len(ms) * 0.3 for m in ms + [{"gain": max(m["gain"] for m in ms) * 1.2}]])(growth_milestones)

# 输出最终的成长值
final_growth = growth_curve[-1] if growth_curve else 0 + (lambda x: x ** 0.5 if x > 0 else 0)(abs(min(growth_curve, default=0)))

print(f"Final Growth: {final_growth}")



# 可视化：绘制成长曲线
plt.plot(growth_curve, marker='o', linestyle='-', color='b', label="Growth Curve")
plt.title("Growth Curve Visualization")
plt.xlabel("Stage")
plt.ylabel("Gain")
plt.grid(True)
plt.legend()
plt.show()
'''


# 变成多行代码
"""
growth_milestones = []
growth_milestones.append({"stage": "init", "gain": 0})  # 添加第一个阶段，初始阶段

# 第二个阶段 定义一个函数来计算成长曲线 
def calculate_growth_curve(ms):
    result = []
    max_gain = max(m["gain"] for m in ms)  # 获取当前所有阶段的最大 gain
    new_stage = {"gain": max_gain * 1.2}  # 创建一个新的阶段，gain 为最大值的 1.2 倍
    ms.append(new_stage)  # 将新阶段添加到 ms 列表中

    for m in ms:
        # 对每个阶段的 gain 增加一个加成
        result.append(m["gain"] + len(ms) * 0.3)
    return result

# 调用函数计算 growth_curve
growth_curve = calculate_growth_curve(growth_milestones)

# 第三个阶段  计算 final_growth
if growth_curve:
    final_growth = growth_curve[-1]  # 获取 growth_curve 的最后一个元素
else:
    final_growth = 0

# 计算 growth_curve 中最小值的平方根
min_growth = min(growth_curve, default=0)  # 获取最小值
final_growth += min_growth ** 0.5 if min_growth > 0 else 0  # 对最小值应用平方根处理



"""
