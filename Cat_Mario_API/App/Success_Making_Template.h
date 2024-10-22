#pragma once
class Success_Making_Template
{
public:
	// constrcuter destructer
	Success_Making_Template();
	~Success_Making_Template();

	// delete Function
	Success_Making_Template(const Success_Making_Template& _Other) = delete;
	Success_Making_Template(Success_Making_Template&& _Other) noexcept = delete;
	Success_Making_Template& operator=(const Success_Making_Template& _Other) = delete;
	Success_Making_Template& operator=(Success_Making_Template&& _Other) noexcept = delete;

protected:

private:
};

