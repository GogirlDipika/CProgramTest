



pipeline {
    agent any
    
    stages {
        stage('checkout') {
            steps {
                checkout scmGit(branches: [[name: '*/demo_private']], extensions: [], userRemoteConfigs: [[credentialsId: 'PAT_Jenkins', url: 'https://github.com/surajkumarbarik/demo_sonarqube_private.git']])
            }
        }
        
        stage('clone') {
            steps {
                git branch: 'demo_private', credentialsId: 'PAT_Jenkins', url: 'https://github.com/surajkumarbarik/demo_sonarqube_private.git'
            }
        }
    }
}

       



