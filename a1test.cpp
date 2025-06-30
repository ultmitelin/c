#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

const size_t MEMORY_LIMIT = 100000;  // 内存限制：最多同时处理 100,000 个 int
const std::string INPUT_FILE = "input.dat";
const std::string OUTPUT_FILE = "sorted_output.dat";

// 第一步：分块排序并将每个块写入临时文件
int sortChunks(const std::string& inputFilePath, size_t chunkSize) {
  std::ifstream inFile(inputFilePath, std::ios::binary);
  if (!inFile) {
    std::cerr << "无法打开输入文件: " << inputFilePath << std::endl;
    return -1;
  }

  std::vector<int> buffer(chunkSize);
  int chunkNumber = 0;

  while (true) {
    // 读取一块数据
    inFile.read(reinterpret_cast<char*>(buffer.data()),
                chunkSize * sizeof(int));
    size_t elementsRead = inFile.gcount() / sizeof(int);

    if (elementsRead == 0) break;

    // 排序这一块
    std::sort(buffer.begin(), buffer.begin() + elementsRead);

    // 写入临时文件
    std::string tempFileName =
        "temp_chunk_" + std::to_string(chunkNumber++) + ".dat";
    std::ofstream outFile(tempFileName, std::ios::binary);
    outFile.write(reinterpret_cast<const char*>(buffer.data()),
                  elementsRead * sizeof(int));
    outFile.close();
  }

  inFile.close();
  return chunkNumber;
}

// 第二步：k 路归并（使用优先队列）
void mergeChunks(int numChunks) {
  std::vector<std::ifstream*> filePointers(numChunks);
  std::vector<int> currentValues(numChunks);
  std::vector<bool> hasMoreData(numChunks, true);

  // 打开所有临时文件
  for (int i = 0; i < numChunks; ++i) {
    std::string tempFileName = "temp_chunk_" + std::to_string(i) + ".dat";
    filePointers[i] = new std::ifstream(tempFileName, std::ios::binary);
    if (!(*filePointers[i])) {
      std::cerr << "无法打开临时文件: " << tempFileName << std::endl;
      exit(1);
    }
  }

  // 定义优先队列结构：保存的是 (值, 文件索引)
  auto comp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first > b.first;
  };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      decltype(comp)>
      minHeap(comp);

  // 初始加载每个文件的第一个元素
  for (int i = 0; i < numChunks; ++i) {
    filePointers[i]->read(reinterpret_cast<char*>(&currentValues[i]),
                          sizeof(int));
    if (filePointers[i]->gcount() == 0) {
      hasMoreData[i] = false;
    } else {
      minHeap.push({currentValues[i], i});
    }
  }

  // 输出文件
  std::ofstream outFile(OUTPUT_FILE, std::ios::binary);

  // 开始归并
  while (!minHeap.empty()) {
    auto [minVal, fileIndex] = minHeap.top();
    minHeap.pop();

    outFile.write(reinterpret_cast<const char*>(&minVal), sizeof(int));

    // 从该文件读取下一个值
    if (hasMoreData[fileIndex]) {
      filePointers[fileIndex]->read(
          reinterpret_cast<char*>(&currentValues[fileIndex]), sizeof(int));
      if (filePointers[fileIndex]->gcount() > 0) {
        minHeap.push({currentValues[fileIndex], fileIndex});
      } else {
        hasMoreData[fileIndex] = false;
      }
    }
  }

  outFile.close();

  // 清理临时文件和流
  for (int i = 0; i < numChunks; ++i) {
    delete filePointers[i];
    std::string tempFileName = "temp_chunk_" + std::to_string(i) + ".dat";
    std::remove(tempFileName.c_str());
  }
}

// 主函数：执行整个外部排序过程
int main() {
  // Step 1: 分块排序生成临时文件
  std::cout << "开始分块排序..." << std::endl;
  int numChunks = sortChunks(INPUT_FILE, MEMORY_LIMIT);
  if (numChunks <= 0) {
    std::cerr << "没有数据可排序。" << std::endl;
    return 1;
  }
  std::cout << "共生成 " << numChunks << " 个临时文件。" << std::endl;

  // Step 2: 归并所有临时文件
  std::cout << "开始归并..." << std::endl;
  mergeChunks(numChunks);
  std::cout << "排序完成，结果已写入: " << OUTPUT_FILE << std::endl;

  return 0;
}