#pragma once

#include "expr.h"
#include "statements/statement.h"

namespace csql {
// Represents the result of the SQLParser.
// If parsing was successful it contains a list of SQLStatement.
class SQLParserResult {
 public:
  SQLParserResult();
  SQLParserResult(std::shared_ptr<SQLStatement> stmt);
  virtual ~SQLParserResult() = default;
  void setIsValid(bool isValid);
  bool isValid() const;
  size_t size() const;
  void setErrorDetails(std::string errorMsg, int errorLine, int errorColumn);
  void setTokens(std::shared_ptr<std::vector<std::string>> tokens);
  const std::string& errorMsg() const;
  int errorLine() const;
  int errorColumn() const;
  void addStatement(std::shared_ptr<SQLStatement> stmt);
  std::shared_ptr<SQLStatement> getStatement(size_t index) const;
  const std::vector<std::shared_ptr<SQLStatement>>& getStatements() const;
  void reset();

 private:
  std::vector<std::shared_ptr<SQLStatement>> statements_;
  bool isValid_;
  std::string errorMsg_;
  int errorLine_;
  int errorColumn_;
  std::shared_ptr<std::vector<std::string>> tokens_;
};

}  // namespace csql
