#ifndef VIEWER_SRC_MODEL_FILEREADER_H_
#define VIEWER_SRC_MODEL_FILEREADER_H_

#include "figure.h"

namespace awfl {
class FileReader {
 public:
  FileReader() = default;
  ~FileReader() = default;

  void GetDataFromFile(Figure& figure, const std::string& path);

  void SetFileName(const std::string& path);

 private:
  std::string filePath_;

  std::pair<std::size_t, std::size_t> GetNumbers_();
  void SplitInputString_(std::vector<std::string>& arr, std::string& buf);
  void ReadData_(Figure& figure);
};
}  // namespace awfl

#endif  // VIEWER_SRC_MODEL_FILEREADER_H_
